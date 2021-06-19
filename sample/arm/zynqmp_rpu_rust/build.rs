use cc::Build;
use std::{env, error::Error, fmt, fmt::Display, fs::File, io::Write, path::PathBuf};

use std::process::Command;

#[derive(Debug)]
struct BuildError {
    message: String,
}

impl BuildError {
    fn new(message: &str) -> Box<BuildError> {
        Box::new(BuildError {
            message: message.to_string(),
        })
    }
}

impl Error for BuildError {}

impl Display for BuildError {
    fn fmt(&self, f: &mut fmt::Formatter) -> fmt::Result {
        write!(f, "{}", self.message)
    }
}

fn main() -> Result<(), Box<dyn Error>> {
    // ITRONカーネルのパス
    let kernel_path = "../../../kernel";

    // カーネルビルド(CargoでTARGET環境変数ができてしまうので上書き)
    let status = Command::new("make")
        .args(&[
            "TARGET=libhosv4a",
            "-C",
            &format!("{}/build/arm/cortex_r5/gcc", kernel_path),
        ])
        .status()
        .expect("kernel build command failed");
    if !status.success() {
        return Err(BuildError::new("kernel build command failed"));
    }

    // コンフィギュレータ実行
    let status = Command::new("cpp")
        .args(&["-E", "src/system.cfg", "src/system.i"])
        .status()
        .expect("cpp command failed");
    if !status.success() {
        return Err(BuildError::new("cpp command failed"));
    }

    let status = Command::new("../../../cfgrtr/build/gcc/h4acfg-cortex_r5")
        .args(&[
            "src/system.i",
            "-c",
            "src/kernel_cfg.c",
            "-i",
            "src/kernel_id.h",
        ])
        .status()
        .expect("h4acfg command failed");
    if !status.success() {
        return Err(BuildError::new("h4acfg command failed"));
    }

    let status = Command::new("rm")
        .args(&["-f", "src/system.i"])
        .status()
        .expect("rm command failed");
    if !status.success() {
        return Err(BuildError::new("rm command failed"));
    }

    // アセンブラとCをコンパイル
    let src_files = vec![
        ["src/vectors.S", "vectors"],
        ["src/crt0.S", "crt0"],
        ["src/hw_setup.c", "hw_setup"],
        ["src/kernel_cfg.c", "kernel_cfg"],
    ];

    for name in src_files.into_iter() {
        Build::new()
            .flag("-mfpu=vfpv3-d16")
            .flag("-mthumb-interwork")
            .flag("-mfloat-abi=softfp")
            .flag("-Wno-unused-parameter")
            .flag("-Wno-missing-field-initializers")
            .flag(&format!("-I{}/include", kernel_path))
            .file(name[0])
            .compile(name[1]);
    }

    // ライブラリパス追加(あってるか自信なし)
    let out_dir = PathBuf::from(env::var_os("OUT_DIR").unwrap());
    println!("cargo:rustc-link-search={}", out_dir.display());
    println!(
        "cargo:rustc-link-search={}/build/arm/cortex_r5/gcc",
        kernel_path
    );

    // リンカスクリプトををビルドディレクトリに
    File::create(out_dir.join("link.lds"))?.write_all(include_bytes!("link.lds"))?;

    Ok(())
}

use std::{env, error::Error, fs::File, io::Write, path::PathBuf};
use cc::Build;

use std::process::Command;


fn main() -> Result<(), Box<dyn Error>> {

    // コンフィギュレータ実行
    Command::new("cpp")
        .args(&["-E", "src/system.cfg", "src/system.i"])
        .output()
        .expect("cpp command failed");
    
    Command::new("../../../cfgrtr/build/gcc/h4acfg-cortex_r5")
        .args(&["src/system.i", "-c", "src/kernel_cfg.c", "-i", "src/kernel_id.h"])
        .output()
        .expect("h4acfg command failed");

    Command::new("rm")
        .args(&["-f", "src/system.i"])
        .output()
        .expect("rm command failed");

    
    // ライブラリパス追加(あってるか自信なし)
    let out_dir = PathBuf::from(env::var_os("OUT_DIR").unwrap());
    println!("cargo:rustc-link-search={}", out_dir.display());
    println!("cargo:rustc-link-search=/home/ryuji/git-work/hos-v4a/kernel/build/arm/cortex_r5/gcc");

    // リンカスクリプトををビルドディレクトリに
    File::create(out_dir.join("link.lds"))?.write_all(include_bytes!("link.lds"))?;

    // アセンブラとCをコンパイル
    Build::new()
        .flag("-mfpu=vfpv3-d16")
        .flag("-mthumb-interwork")
        .flag("-mfloat-abi=softfp")
        .file("src/vectors.S")
        .compile("vectors");

    Build::new()
        .flag("-mfpu=vfpv3-d16")
        .flag("-mthumb-interwork")
        .flag("-mfloat-abi=softfp")
        .file("src/crt0.S")
        .compile("crt0");

    Build::new()
        .flag("-mfpu=vfpv3-d16")
        .flag("-mthumb-interwork")
        .flag("-mfloat-abi=softfp")
        .flag("-I/home/ryuji/git-work/hos-v4a/kernel/include")
        .file("src/hw_setup.c")
        .compile("hw_setup");
    
    Build::new()
        .flag("-mfpu=vfpv3-d16")
        .flag("-mthumb-interwork")
        .flag("-mfloat-abi=softfp")
        .flag("-Wno-unused-parameter")
        .flag("-Wno-missing-field-initializers")
        .flag("-I/home/ryuji/git-work/hos-v4a/kernel/include")
        .file("src/kernel_cfg.c")
        .compile("kernel_cfg");

    Build::new()
        .flag("-mfpu=vfpv3-d16")
        .flag("-mthumb-interwork")
        .flag("-mfloat-abi=softfp")
        .flag("-Wno-unused-parameter")
        .flag("-I/home/ryuji/git-work/hos-v4a/kernel/include")
        .file("src/ostimer.c")
        .compile("ostimer");

    Build::new()
        .flag("-mfpu=vfpv3-d16")
        .flag("-mthumb-interwork")
        .flag("-mfloat-abi=softfp")
        .flag("-I/home/ryuji/git-work/hos-v4a/kernel/include")
        .file("src/uart.c")
        .compile("uart");

    Ok(())
}

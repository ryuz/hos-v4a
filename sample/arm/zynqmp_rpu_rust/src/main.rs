// -------------------------------------------------------------
//  Sample program for Hyper Operating System V4 Advance
//  食事する哲学者の問題 Rust 版
//
//  Copyright (C) 1998-2021 by Project HOS
//  https://github.com/ryuz/hos-v4a
//  http://sourceforge.jp/projects/hos/
// -------------------------------------------------------------

#![no_main]
#![no_std]

#[link(name = "hosv4a")]
mod ostimer;
#[macro_use]
mod uart;
mod sample;

use uart::*;

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_panic: &PanicInfo<'_>) -> ! {
    println!("\r\n!!!panic!!!");
    loop {}
}

// ITRON API
extern "C" {
    fn vsta_knl(); // HOS-V4a独自
}

// main
#[no_mangle]
pub unsafe extern "C" fn main() -> ! {
    vsta_knl(); // カーネル起動
    loop {}
}

// end of file

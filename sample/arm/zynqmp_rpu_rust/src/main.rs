#![no_main]
#![no_std]

#[link(name = "hosv4a")]


use core::panic::PanicInfo;

#[panic_handler]
fn panic(_panic: &PanicInfo<'_>) -> ! {
    loop {}
}


extern {
    fn vsta_knl();
}

#[no_mangle]
pub unsafe extern "C" fn main() -> ! {
    vsta_knl();    // カーネル起動
    loop {}
}


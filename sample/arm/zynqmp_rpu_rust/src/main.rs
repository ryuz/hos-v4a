#![no_main]
#![no_std]

#[link(name = "hosv4a")]

mod my_uart;

use core::panic::PanicInfo;

#[panic_handler]
fn panic(_panic: &PanicInfo<'_>) -> ! {
    uart_print_string("\r\npanic\r\n");
    loop {}
}


// ITRON API
extern {
    fn vsta_knl();  // HOS-V4a独自
    fn dly_tsk(id: i32) -> i32;
    fn wai_sem(id: i32) -> i32;
    fn pol_sem(id: i32) -> i32;
    fn sig_sem(id: i32) -> i32;
}


// main
#[no_mangle]
pub unsafe extern "C" fn main() -> ! {
    vsta_knl();    // カーネル起動
    loop {}
}

// ランダムな時間待ち
static mut R : i32 = 1;
fn rand_wait() {
    unsafe {
        R = R.wrapping_mul(1103515245).wrapping_add(12345);
        dly_tsk(R&0x3ff + 100);
    }
}

// アプリ初期化
#[no_mangle]
pub unsafe extern "C" fn Sample_Initialize()
{
//  Uart_Initialize();
    uart_print_string("Program Start\r\n");
}

// タスク
#[no_mangle]
pub unsafe extern "C" fn Sample_Task(num: i32) -> !
{
    print_state(num, "task start");

	// いわゆる哲学者の食事の問題
    loop {
        // 適当な時間考える
		print_state(num, "thinking");
		rand_wait();
		
		// 左右のフォークを取るまでループ
		loop {
			// 左から順に取る
			wai_sem(left_id(num));
			if pol_sem(right_id(num)) == 0 {
				break;	// 両方取れた
			}
			sig_sem(left_id(num));	// 取れなければ離す
			
			// 適当な時間待つ
			print_state(num, "hungry");
			rand_wait();
            
			// 右から順に取る
			wai_sem(right_id(num));
			if pol_sem(left_id(num)) == 0 {
				break;	// 両方取れた
			}
			sig_sem(right_id(num));	// 取れなければ離す

			// 適当な時間待つ
			print_state(num, "hungry");
			rand_wait();
		}
		
		// 適当な時間、食べる
		print_state(num, "eating");
		rand_wait();
		
		// フォークを置く
		sig_sem(left_id(num));
		sig_sem(right_id(num));
    }
}


// 左のフォーク相当のセマフォID
fn left_id(num: i32) -> i32 {
    if num <= 1 {5} else {num-1}
}

// 右のフォーク相当のセマフォID
fn right_id(num: i32) -> i32 {
    if num >= 5 {1} else {num+1}
}


// 状態表示
fn print_state(num: i32, state:&str)
{
    uart_print_int(num);
    uart_print_string(" : ");
    uart_print_string(state);
    uart_print_string("\r\n");
}

// 数字出力
fn uart_print_int(i: i32)
{
    my_uart::uart_write('0' as i32 + i);
}

// 文字列出力
fn uart_print_string(s: &str)
{
    for i in s.chars() {
        my_uart::uart_write(i as i32);
    }
}


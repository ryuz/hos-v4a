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
mod uart;

use uart::*;


use core::panic::PanicInfo;

#[panic_handler]
fn panic(_panic: &PanicInfo<'_>) -> ! {
    println!("\r\n!!!panic!!!");
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

// アプリ初期化
#[no_mangle]
pub unsafe extern "C" fn Sample_Initialize()
{
    println!("Program Start");
}

// タスク(哲学者に見立てたタスク)
#[no_mangle]
pub unsafe extern "C" fn Sample_Task(num: i32) -> !
{
    let left_id  = if num <= 1 {5} else {num-1};    // 左のフォーク相当のセマフォID
    let right_id = if num >= 5 {1} else {num+1};    // 右のフォーク相当のセマフォID

    random_wait(num, "task start");

	// いわゆる哲学者の食事の問題
    loop {
        // 適当な時間考える
		random_wait(num, "thinking");
		
		// 左右のフォークを取るまでループ
		loop {
			// 左から順に取る
			wai_sem(left_id);
			if pol_sem(right_id) == 0 {
				break;	// 両方取れた
			}
			sig_sem(left_id);	// 取れなければ離す
			
			// 適当な時間空腹なまま待つ
			random_wait(num, "hungry");
            
			// 右から順に取る
			wai_sem(right_id);
			if pol_sem(left_id) == 0 {
				break;	// 両方取れた
			}
			sig_sem(right_id);	// 取れなければ離す

			// 適当な時間待つ
			random_wait(num, "hungry");
		}
		
		// 適当な時間、食べる
		random_wait(num, "eating");
		
		// フォークを置く
		sig_sem(left_id);
		sig_sem(right_id);
    }
}

// ランダムな時間待ち
static mut R : i32 = 1;
fn random_wait(num: i32, state:&str) {
    // 状態を表示
    println!("{} : {}", num, state);

    // ランダムな時間待つ
    unsafe {
        R = R.wrapping_mul(1103515245).wrapping_add(12345); // 線形合同法で乱数生成
        dly_tsk(R&0x3ff + 100); // タスク遅延
    }
}


// end of file
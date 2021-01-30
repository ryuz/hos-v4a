// -------------------------------------------------------------
//  Sample program for Hyper Operating System V4 Advance
//  OSタイマ
//
//  Copyright (C) 1998-2021 by Project HOS
//  https://github.com/ryuz/hos-v4a
//  http://sourceforge.jp/projects/hos/
// -------------------------------------------------------------


// ITRON API
extern {
    fn vchg_ilv(intno: i32, ilv: i32) -> i32;  // HOS-V4a独自
    fn ena_int(intno: i32) -> i32;
    fn isig_tim();
}


// TTCレジスタ
#[repr(C)]
struct Ttc {
    pub clock_control_1       : u32,
    pub clock_control_2       : u32,
    pub clock_control_3       : u32,
    pub counter_control_1     : u32,
    pub counter_control_2     : u32,
    pub counter_control_3     : u32,
    pub counter_value_1       : u32,
    pub counter_value_2       : u32,
    pub counter_value_3       : u32,
    pub interval_counter_1    : u32,
    pub interval_counter_2    : u32,
    pub interval_counter_3    : u32,
    pub match_1_counter_1     : u32,
    pub match_1_counter_2     : u32,
    pub match_1_counter_3     : u32,
    pub match_2_counter_1     : u32,
    pub match_2_counter_2     : u32,
    pub match_2_counter_3     : u32,
    pub match_3_counter_1     : u32,
    pub match_3_counter_2     : u32,
    pub match_3_counter_3     : u32,
    pub interrupt_register_1  : u32,
    pub interrupt_register_2  : u32,
    pub interrupt_register_3  : u32,
    pub interrupt_enable_1    : u32,
    pub interrupt_enable_2    : u32,
    pub interrupt_enable_3    : u32,
    pub event_control_timer_1 : u32,
    pub event_control_timer_2 : u32,
    pub event_control_timer_3 : u32,
    pub event_register_1      : u32,
    pub event_register_2      : u32,
    pub event_register_3      : u32,
}

const OS_TIMER_INTNO :i32 = 74;


// OS用タイマ初期化ルーチン
#[no_mangle]
pub unsafe extern "C" fn OsTimer_Initialize()
{
    // TTC0 : 0xFF110000
    // TTC1 : 0xFF120000
    // TTC2 : 0xFF140000
    // TTC3 : 0xFF140000
    let ttc = &mut *(0xFF130000 as *mut Ttc);

    vchg_ilv(OS_TIMER_INTNO, 0xa0);
    ena_int(OS_TIMER_INTNO);

    // タイマ動作開始
    core::ptr::write_volatile(&mut ttc.counter_control_1, 0x31);        // stop and reset
    core::ptr::write_volatile(&mut ttc.counter_control_1, 0x21);        // stop

    core::ptr::write_volatile(&mut ttc.clock_control_1, 0x03);          // PS_VAL:1, PS_EN:1
    core::ptr::write_volatile(&mut ttc.interval_counter_1, 25000-1);    // 1kHz (CPU_1x:100MHz)

    core::ptr::write_volatile(&mut ttc.interrupt_register_1, 0x01);     // Interrupt : Interval
    core::ptr::write_volatile(&mut ttc.interrupt_enable_1, 0x01);       // Interrupt enable

    core::ptr::write_volatile(&mut ttc.counter_control_1, 0x22);        // start
}


// タイマ割込みハンドラ
#[no_mangle]
pub unsafe extern "C" fn OsTimer_Isr()
{
    let ttc = &mut *(0xFF130000 as *mut Ttc);

    //  割込み要因クリア
    core::ptr::read_volatile(&mut ttc.interrupt_register_1); // 読み出すとクリア

    // タイムティック供給
    isig_tim();
}

// end of file

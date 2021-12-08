#once

#ruledef {
    ; System
    nop => 0x00
    rst => 0x01
    brk => 0x02
    cpu => 0x03

    ; Arithmetic
    inc => 0x10
    dec => 0x11
    icc => 0x12
    dcb => 0x13
    add => 0x14
    sub => 0x15
    mul => 0x16
    div => 0x17
    mod => 0x18
    adc => 0x19
    sbb => 0x1A
    mls => 0x1B
    dvs => 0x1C
    mds => 0x1D

    ; Boolean
    and => 0x20
    or => 0x21
    xor => 0x22
    eq => 0x23
    neq => 0x24
    lt => 0x25
    lte => 0x26
    gt => 0x27
    gte => 0x28
    zero => 0x29
    nzero => 0x2A

    ; Binary
    band => 0x30
    bor => 0x31
    bxor => 0x32
    bnot => 0x33
    bset => 0x34
    brst => 0x35
    btst => 0x36

    ; Stack
    push {i : i8} => 0x40 @ i
    push [{a : i24}] => 0x41 @ le(a)
    pop => 0x42
    pop [{a : i24}] => 0x43 @ le(a)
    sst {start : i24}, {size : i24} => 0x44 @ le(start) @ le(size)
    sstx => 0x45
    popn {i : i24} => 0x46 @ le(i)
    pop [[{a : i24}]] => 0x47 @ le(a)
    top [{a : i24}] => 0x48 @ le(a)
    top [[{a : i24}]] => 0x49 @ le(a)
    push [[{a : i24}]] => 0x4A @ le(a)

    ; Control Flow
    jmp {i : i24} => 0x50 @ le(i)
    jps => 0x51
    jpz {i : i24} => 0x52 @ le(i)
    jnz {i : i24} => 0x53 @ le(i)
    call {i : i24} => 0x54 @ le(i)
    calls => 0x55
    callz {i : i24} => 0x56 @ le(i)
    calnz {i : i24} => 0x57 @ le(i)
    ret => asm { jps }

    ; I/O
    out => 0x60
    in => 0x61

    ; 24-bit support

    ; Arithmetic
    inc24 => 0xFF @ 0x02 @ 0x10
    add24 => 0xFF @ 0x02 @ 0x14

    ; Boolean
    gte24 => 0xFF @ 0x02 @ 0x28

    ; Stack
    push24 [{a : i24}] => 0xFF @ 0x02 @ 0x41 @ le(a)
    pop24 [{a : i24}] => 0xFF @ 0x02 @ 0x43 @ le(a)
}

#bankdef stack {
    #addr (5 * 1024 * 1024) - (5 * 1024)
    #size 1 * 1024
}

#bankdef term {
    #addr (5 * 1024 * 1024) - (4 * 1024)
    #size 4 * 1024
}

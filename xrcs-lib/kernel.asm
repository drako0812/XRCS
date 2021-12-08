#once
#include "../XRCS.def.asm"
#include "baselib/utility.asm"

#bankdef kcode {
    #addr 0x000000
    #outp 0x000000
    #size 0x4FEC00
}

#bank kcode
kmain:
    inc([.test1])
    dec([.test1])
    add(1, 2)
    pop
    jmp main

.test1: #d 0x00
.test2: #d 0x02

#include "baselib.asm"
#include "xrcsterm.asm"

main = 0x800000

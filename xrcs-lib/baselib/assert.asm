; Approximates assert.h

#once

; @function assert(condition)
; TODO: Add some additional functionality
#bank kcode
_assert:
    jpz .failed
    ret
    .failed:
        brk
        ret

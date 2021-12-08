; This file defines various utility macro-like instructions

#once

#ruledef {
    inc([{a : i24}]) => asm {
        push [a]
        inc
    }
    inc([[{a : i24}]]) => asm {
        push [[a]]
        inc
    }

    dec([{a : i24}]) => asm {
        push [a]
        dec
    }
    dec([[{a : i24}]]) => asm {
        push [[a]]
        dec
    }

    add({a : i8}, {b : i8}) => asm {
        push a
        push b
        add
    }

    ; TODO: add more arithmetic operations

    if_eq([{a : i24}], {i : i8}, {on_true : i24}) => asm {
        push [a]
        push i
        eq
        jnz on_true
    }

    if_eq([{a : i24}], {i : i8}, {on_true : i24}, {on_false : i24}) => asm {
        push [a]
        push i
        eq
        jnz on_true
        jmp on_false
    }

    if_eq([{a : i24}], [{b : i24}], {on_true : i24}) => asm {
        push [a]
        push [b]
        eq
        jnz on_true
    }

    if_eq([{a : i24}], [{b : i24}], {on_true : i24}, {on_false : i24}) => asm {
        push [a]
        push [b]
        eq
        jnz on_true
        jmp on_false
    }

    if_eq([{a : i24}], [[{b : i24}]], {on_true : i24}) => asm {
        push [a]
        push [[b]]
        eq
        jnz on_true
    }

    if_eq([{a : i24}], [[{b : i24}]], {on_true : i24}, {on_false : i24}) => asm {
        push [a]
        push [[b]]
        eq
        jnz on_true
        jmp on_false
    }

}

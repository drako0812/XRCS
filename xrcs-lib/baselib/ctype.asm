; Approximates ctype.h

#once

; @function isalnum(ch)
;
; int isalnum(char ch) {
;     if((ch >= 48) && (ch <= 57)) {
;         return 1;
;     } else if((ch >= 65) && (ch <= 90)) {
;         return 1;
;     } else if((ch >= 97) && (ch <= 122)) {
;         return 1;
;     }
;     return 0;
; }
#bank kcode
_isalnum:
    pop24 [.ret]
    pop [.ch]

.if_gte_97:
    push 97
    push [.ch]
    gte
    jnz .is_gte_97 ; if(ch >= 97)

.if_gte_65:
    push 65
    push [.ch]
    gte
    jnz .is_gte_65 ; if(ch >= 65)

.if_gte_48:
    push 48
    push [.ch]
    gte
    jnz .is_gte_48 ; if(ch >= 48)
    jmp .return_false

.is_gte_48:
    push 57
    push [.ch]
    lte
    jpz .return_true ; if(ch <= 57)
    jmp .return_false

.is_gte_65:
    push 90
    push [.ch]
    lte
    jpz .return_true ; if(ch <= 90)
    jmp .if_gte_48

.is_gte_97:
    push 122
    push [.ch]
    lte
    jpz .return_true ; if(ch <= 122)
    jmp .if_gte_65

.return_false:
    push 0
    push24 [.ret]
    ret

.return_true:
    push 1
    push24 [.ret]
    ret

.ret:
    #d 0x000000
.ch:
    #d 0x00

; @function isalpha(ch)
;
; int isalpha(char ch) {
;     if((ch >= 65) && (ch <= 90)) {
;         return 1;
;     } else if((ch >= 97) && (ch <= 122)) {
;         return 1;
;     }
;     return 0;
; }
#bank kcode
_isalpha:
    pop24 [.ret]
    pop [.ch]

.if_gte_97:
    push 97
    push [.ch]
    gte
    jnz .is_gte_97 ; if(ch >= 97)

.if_gte_65:
    push 65
    push [.ch]
    gte
    jnz .is_gte_65 ; if(ch >= 65)
    jmp .return_false

.is_gte_65:
    push 90
    push [.ch]
    lte
    jpz .return_true ; if(ch <= 90)
    jmp .return_false

.is_gte_97:
    push 122
    push [.ch]
    lte
    jpz .return_true ; if(ch <= 122)
    jmp .if_gte_65

.return_false:
    push 0
    push24 [.ret]
    ret

.return_true:
    push 1
    push24 [.ret]
    ret

.ret:
    #d 0x000000
.ch:
    #d 0x00

; TODO: Implement islower, isupper, isdigit, isxdigit, iscntrl, isgraph, isspace, isblank, isprint, ispunct, tolower, toupper

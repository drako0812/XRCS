; Approximates string.h

#once

; TODO: Implement strcpy, strncpy, strcat, strncat, strxfrm, strdup, strndup

; TODO: Implement strlen, strcmp, strncmp, strcoll, strchr, strrchr, strspn, strpbrk, strstr, strtok

; TODO: Implement memchr, memcmp

; @function memset(dest, value, count)
;
; void * memset(void * dest, char ch, int count) {
;     for(;dest < dest + count; dest++) {
;         *dest = ch;
;     }
; }
#bank kcode
_memset:
    pop24 [.ret]
    pop24 [.count]
    pop [.value]
    pop24 [.dest]
    push24 [.ret]
    
    ; bound = dest + count
    push24 [.dest]
    push24 [.count]
    add24
    pop24 [.bound]

.loop:
    ; dest < dest + count
    push24 [.bound]
    push24 [.dest]
    gte24
    jnz .end

    ; *dest = ch
    push [.value]
    pop [[.dest]]

    ; dest++
    push24 [.dest]
    inc24
    pop24 [.dest]

    jmp .loop

.end:
    ret

.dest:
    #d 0x000000
.value:
    #d 0x00
.count:
    #d 0x000000
.ret:
    #d 0x000000
.bound:
    #d 0x000000

; @function memcpy(dest, src, count)
;
; void * memcpy(void * dest, void * src, int count) {
;     for(;dest < dest + count; dest++, src++) {
;         *dest = *src;
;     }
; }
#bank kcode
_memcpy:
    pop24 [.ret]
    pop24 [.count]
    pop24 [.src]
    pop24 [.dest]
    push24 [.ret]

    ; bound = dest + count
    push24 [.dest]
    push24 [.count]
    add24
    pop24 [.bound]

.loop:
    ; dest < dest + count
    push24 [.bound]
    push24 [.dest]
    gte24
    jnz .end

    ; *dest = *src
    push [[.src]]
    pop [[.dest]]

    ; dest++
    push24 [.dest]
    inc24
    pop24 [.dest]

    ; src++
    push24 [.src]
    inc24
    pop24 [.src]

    jmp .loop

.end:
    ret

.dest:
    #d 0x000000
.src:
    #d 0x000000
.count:
    #d 0x000000
.ret:
    #d 0x000000
.bound:
    #d 0x000000

; TODO: Implement memmove, memccpy

; TODO: Implement strerror


;nasm -f elf64 -g powFuncASM.asm -o powFuncASM.o
global powFuncASM
section .text
;n->rdi x->xmm0
powFuncASM:
    xorpd xmm1,xmm1
    xorpd xmm2,xmm2
    mov r8,rdi
    mov r14,rdi
    mov rax,2
    mul r8
    mov r8,rax
    mov r9,1
    mov r10,rdi
    mov r11,1
    ;cvtsi2sd xmm1,r10
    movsd xmm1,xmm0
    mov r12,0
    cmp r12,rdi
    je zero
bucle:
    cmp r9,r8
    je impar
    mulpd xmm0,xmm1
    inc r9
    jmp bucle
impar:
    mov rax,r14
    mov r12,2
    div r12
    cmp rdx,0
    je done
    mov r11,-1
done:
    cvtsi2sd xmm2,r11
    mulpd xmm0,xmm2
    ret
zero:
    mov r15,1
    cvtsi2sd xmm0,r15
    ret
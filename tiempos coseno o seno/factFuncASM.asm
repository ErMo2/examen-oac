
;nasm -f elf64 -g factFuncASM.asm -o factFuncASM.o
global factFuncASM
section .text
;n->rdi
factFuncASM:
    xorpd xmm0,xmm1
    mov rax,2
    mov r8,rdi
    mul r8
    mov r8,rax
    mov r9,0
    mov r10,1
    cvtsi2sd xmm0,r10
    ;cmp rdi,r9
    ;je zero
bucle:
    cmp r8,r9
    je done
    cvtsi2sd xmm1,r10
    mulpd xmm0,xmm1
    inc r9
    inc r10
    jmp bucle
done: 

    ret
zero:
    mov r15,1
    cvtsi2sd xmm0,r15
    ret
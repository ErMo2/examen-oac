	global powerimpASM
	section .text

powerimpASM:
	;rdi=n
	;xmm0 = x
	; rdx rcx
	mov r11, rdi
	xorpd xmm1, xmm1
	xorpd xmm2, xmm2
	xorpd xmm3, xmm3
	xorpd xmm4, xmm4
	mov rdx, 2
	mov rcx, 1
	cvtsi2sd xmm1, rdi
	cvtsi2sd xmm2, rdx
	cvtsi2sd xmm3, rcx
	cvtsi2sd xmm5, rcx
	mulsd xmm1, xmm2
	addsd xmm1, xmm3

	mov rdx, 0
	mov rcx, 1 
	cvtsi2sd xmm2, rdx 
	cvtsi2sd xmm3, rcx
	cvtsi2sd xmm4, rcx
	mov rdx, 0
	
	;potencia = 2n+1 ,x=x    i = 0   ,  resul=1,  , extra =1
	; 1 = 2n+1       0 = x,  2 = 0        3 = 1,     4 = 1
chequeo_impar:
	mov rax, r11
	mov rdx, 0
	mov r15, 2
	div r15
	cmp rdx, 0
	je next
	mov r11, -1
	cvtsi2sd xmm5, r11
next:
	addsd xmm2, xmm4
	mulsd xmm3, xmm0
	ucomisd xmm2, xmm1
	jb next
done:
	mulsd xmm3, xmm5
	movsd xmm0, xmm3
	ret
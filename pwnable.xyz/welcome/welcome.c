/* Canary: True, NX: True, PIC: True, Relro: Full, Stripped: True */
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(int argc, char **argv){
    unsigned long length; /* [rsp] */

    fcn_00000b4e();
    puts("Welcome.");

    register int rax = malloc(0x40000);
    *(uint64_t *)(rax) = 1;
    printf("Leak: %p\n", rax);
    
    printf("Length of your message: ");
    scanf("%lu", &length);
    register char *rbp = malloc(length);

    printf("Enter your message: ");
    read(0, rbp, length);

    write(1, rbp, length);
    rbp[length-1] = '\0';

    if(*(uint64_t *)rax == 0) system("cat /flag");
    return 0;
}
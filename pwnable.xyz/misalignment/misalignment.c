/* Canary: True, NX: True,  PIC: True, Relro: Full */
#include <string.h>
#include <stdint.h>

int main(int argc, char **argv){
    char s[0x98]; /* [rbp-0xa0] */
    int var_a4; /* [rbp-0xa4] */
    setup();
    
    memset(s, 0, 0x98);
    *(uint64_t *)(s+0xf) = 0xdeadbeef;
    
    for(;;){
        var_a4 = scanf("%ld %ld %ld", (long *)(s+0x20), (long *)(s+0x28), (long *)(s+0x30));
        if(var_a4 != 3) break;
        if((*(long *)(s+0x30) > 9) || (*(long *)(s+0x30) < -7)) break;

        ((uint64_t *)s)[(*(long *)(s+0x30))+6] = (*(long *)(s+0x28)) + (*(long *)(s+0x20));
        
        printf("Result: %ld\n", ((uint64_t *)s)[(*(long *)(s+0x30))+6]);
    }
    if(*(uint64_t *)(s+0xf) == 0xb000000b5) win();
    return 0;
}

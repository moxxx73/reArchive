/* Canary: True, NX: True, Relro: Full */
#include <stdlib.h>
#include <string.h>

int limit;

int main(int argc, char **argv){
    int var_18[0xc]; /* [rsp+0x18] */
    char *var_10;    /* [rsp+0x10] */
    long var_8;      /* [rsp+0x08] */
    
    // lea rbx, [var_18]
    // lea r12, [var_10]
    setup();

    var_10 = malloc(0x40);

    for(;;){
        printf("> ");
        memset((char *)var_18, 0, 0x30);
        read(0, var_18, 0x30);

        register long rax = atoi(var_18);
        if(rax == 1) read(0, var_10, 0x20);
        else if(rax == 0){
            if(var_10){
                free(var_10);
                return;
            }else exit(1);
        }
        else if(rax == 2)printf("%p\n", &var_10);
        else if(rax == 3){
            if(limit > 1) continue;
            var_8 = *(__int128_t *)(var_10);
        }else puts("Invalid");
    }

    return 0;
}
/* Canary: True, NX: True, Relro: Partial */
#include <stdint.h>

int main(int argc, char **argv){
    int64_t var_60[10];
    int64_t var_68;
    int64_t var_70;
    int64_t var_78;
    int var_7c;
    setup();
    
    for(;;){
        var_68 = var_70 = var_78 = 0;
        memset((char *)var_60, 0, 0xa*8);
        printf("Input: ");

        var_7c = scanf("%ld %ld %ld", var_78, var_70, var_68);
        if(var_7c != 3) return;

        var_60[var_68] = var_78+var_70;
        printf("Result: %ld", var_60[var_68]);
    }
    return 0;
}
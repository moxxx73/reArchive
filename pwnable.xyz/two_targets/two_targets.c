/* Canary: True, NX: True, Relro: Partial */
#include <string.h>
#include <unistd.h>
#include <stdio.h>

int main(int argc, char **argv);

int read_int32(void){
    char str[0x10];
    read(0, str, 0x10);
    return atoi(str);
}

int auth(char *s){
    //long var_18 = 0;   /* [rbp-0x18] */
    //long var_20 = 0;   /* [rbp-0x20] */
    //long var_28 = 0;   /* [rbp-0x28] */
    //long s1 = 0;       /* [rbp-0x30] */

    char s1[32] = {0}; /* [rbp-0x30] */
    int var_34;        /* [rbp-0x34] */
    int var_38 = 0;    /* [rbp-0x38] */
    char var_39;       /* [rbp-0x39] */
    char *var_48 = s;  /* [rbp-0x48] */

    for(; var_38 <= 31; var_38++){
        /* swap bit order (0x41 -> 0x14) */
        var_39 = (unsigned char)((var_48[var_38])<<4|(var_48[var_38])>>4);
        s1[var_38] = *(unsigned char *)(&main+var_38) ^ var_39;
    }
    var_34 = strncmp(s1, 0x00401d28, 0x20);
    if(var_34 == 1) return 1;
    return 0;
}

void print_menu(void){
    printf("Menu:\n  1. Change name.\n  2. Change nationality.\n  3. Change age.\n  4. Get shell.\n> ");
    return;
}

int main(int argc, char **argv){
    int var_10; /* [rbp-0x10] */
    char s[56]; /* [rbp-0x40] */
    int var_44; /* [rbp-0x44] */

    setup();
    memset(s, 0, 0x38);

    for(;;){
        print_menu();
        var_44 = read_int32();
        if(var_44 == 2){
            printf("nationality: ");
            scanf("%24s", &s[0x20]);
            // continue
        }
        else if(var_44 == 1){
            printf("name: ");
            scanf("%32s", s);
            // continue
        }
        else if(var_44 == 3){
            printf("age: ");
            /* passes integer value and not address of integer */
            scanf("%d", var_10);
            // continue
        }
        else if(var_44 == 4){
            if(auth(s) != 0) win();
        }else puts("Invalid");
    }

    return 0;
}
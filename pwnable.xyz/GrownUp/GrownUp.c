/* Canary: True, NX: True, Relro: Partial  */
#include <stdint.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

char fmt[] = "%s\n\0";
char usr[127];
char *fmtPtr = &fmt;

int main(int argc, char **argv){
    int var_2c;      /* [rbp-0x2c] */
    char *src;       /* [rbp-0x28] */
    char buf[16];    /* [rbp-0x20] */
    //uint64_t var_18; /* [rbp-0x18] */
    setup();

    memset(buf, 0, 16);
    printf("Are you 18 years or older? [y/N]: ");

    /* use this to plant flag address on the stack */
    var_2c = read(0, buf, 0x10);
    buf[var_2c-1] = '\0';
    if(buf[0] == 'y' || buf[0] == 'Y'){
        src = malloc(0x84);
        printf("Name: ");
        read(0, src, 0x80);
        /* strcpy sets null byte after string, making the format string pointer */
        /* point inside the username buffer */
        strcpy(usr, src);
        printf("Welcome ");
        printf(fmt, usr);
    }
    return 0;
}
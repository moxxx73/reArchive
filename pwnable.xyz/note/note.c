/* Canary: True, NX: True */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

char s[32];  /* 0x601480 */
char *desc;  /* 0x6014a0 */

int read_int32(void){
    char str[32]; /* [rbp-0x30] */
    read(0, str, 32);
    return atoi(str);
}

void edit_note(void){
    char *ptr; /* [rbp-0x8] */
    int size;  /* [rbp-0xc] */

    printf("Note len? ");
    /* yeahhhh, the size isnt checked :p */
    size = read_int32();
    
    ptr = malloc(size);
    printf("note: ");

    read(0, ptr, size);
    strncpy(s, ptr, size);
    free(ptr);

    return;
}

void edit_desc(void){
    if(!desc) desc = malloc(0x20);
    printf("desc: ");
    read(0, desc, 0x20);
    return;
}

void print_menu(void){
    printf("Menu: \n 1. Edit note.\n 2. Edit desc.\n 0. Exit\n> ");
    return;
}

int main(int argc, char **argv){
    int var_4; /* [rbp-0x4] */
    setup();
    puts("Note taking 101.");

    for(;;){
        print_menu();
        var_4 = read_int32();
        if(var_4 == 1) edit_note();
        else if(var_4 == 2) edit_desc();
        else if(var_4 == 0) break;
        else puts("Invalid");
    }
    return 0;
}
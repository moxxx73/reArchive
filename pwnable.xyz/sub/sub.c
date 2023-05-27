/* Canary: True, NX: True, PIC: True, Relro: Full, Stripped: True */

int main(int argc, char **argv){
    int rsp;
    int var_4;

    fcn_00000a3e();
    printf("1337 input: ");
    rsp = 0;
    var_4 = 0;

    scanf("%u %u", (unsigned int *)&rsp, (unsigned int *)&var_4);
    /* comparisons are done via jg and jle which treat the integers as signed  */
    if(rsp > 0x1336 || var_4 > 0x1336){
        puts("Sowwy");
        return 0;
    }
    if((rsp-var_4) == 0x1337) system("cat /flag");
    return 0;
}
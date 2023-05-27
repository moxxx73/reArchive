/* Disassembly translation of ./start     */
/* NX: False, Static: True, Canary: False */
#include <stdio.h>
#include <unistd.h>

int main(void){
	char buf[] = "Let's start the CTF:";
	write(STDOUT_FILENO, buf, 20);
	read(STDIN_FILENO, buf, 60);
	return 0;
}
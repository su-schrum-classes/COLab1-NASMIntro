/* 
 * A simple place for scratch work to learn basic assembly commands.
 * 
 * To execute this code, use:
 * bash run.bash
 * Which simply executes the command:
 * nasm -felf64 Assembly.asm && gcc Main.c Assembly.o && ./a.out
 *
 * @author Jacob Schrum, 8/4/2022
 */

#include <stdio.h>

int assemblyProcedure(int);

int main() {
	int result1 = assemblyProcedure(10);
	int result2 = assemblyProcedure(100);
	printf("Result 1 = %d\n", result1);
	printf("Result 2 = %d\n", result2);
}
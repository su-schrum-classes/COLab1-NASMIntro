/* 
 * This code prints the result of multiplying two integers,
 * then prints the result returned by multByDoublingAndHalving,
 * which you must write. Since multByDoublingAndHalving is applied
 * to the same unsigned integer arguments, the result should be
 * the same.
 * 
 * To execute this code, use:
 * bash run.bash
 * Which simply executes the command:
 * nasm -felf64 P1_TODO.asm && gcc P1_Main.c P1_TODO.o && ./a.out
 *
 * @author Jacob Schrum, 8/3/2022
 */

#include <stdio.h>

unsigned int multByDoublingAndHalving(unsigned int, unsigned int);

int main() {
	int A = 13;
	int B = 25;

	printf("%u * %u = %u\n",A,B,A*B);
	printf("%u * %u = %u\n",A,B,multByDoublingAndHalving(A,B));
}
## Computer Organization, Dr. J. Schrum

# Setup

Before running any assembly project in GitHub codespaces, you will need to install NASM, the Netwide Assembler. Execute these commands:
```
sudo apt-get update
sudo apt-get -y install nasm
```

# Programming Assignment 1: Fast Multiplication

Write an assembly language procedure to multiply two integers by doubling and halving. Here is pseudocode to multiply A and B using this approach.

```
Multiply A and B and store result in C:
 C = 0 ; Initialize to 0
 while(B != 0) {
   if(B is odd) {
      C = C+A ; Add copy of A (even number left)
   }
   A = 2*A ; Can be done quickly by shifting left
   B = B/2 ; Can be done quickly by shifting right
 }
```

The file `P1_Main.c` is a simply C program that will launch your assembly code. Note that it has two `printf` calls, and each one prints out a result. The first result comes from standard multiplication, and the second comes from the function that you must define in `P1_TODO.asm`. `P1_TODO.asm` is the only file you need to modify, though adding additional code in `P1_Main.c` to test out multiplication with different numbers would be a good idea. Note that your approach only needs to work for positive integers, which is why the parameter and return types are `unsigned int`. During grading, I will only look at the modified version of `P1_TODO.asm`.

Your solution may not use `MUL`, `DIV`, or any other overly complex/inefficient commands. **Be sure to comment your code!**
 
Test your code by running the command `bash run.sh`
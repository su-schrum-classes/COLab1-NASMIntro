## Computer Organization, Dr. J. Schrum

# Setup

Before running any assembly project in GitHub codespaces, you will need to install NASM, the Netwide Assembler. Execute these commands:
```
sudo apt-get update
sudo apt-get -y install nasm
```

# Lab 1: NASM Intro

After installing NASM, execute the code by running the command `bash run.sh`. It should initially output the following:
```
Result 1 = 30
Result 2 = 120
```
Now, in `Assembly.asm`, change the following line:
```
add eax, 20
```
Change the `20` to `14h` and run the code. You should get the exact same output because `14h` is the hex value of `20`. You could also replace the `20` with `10100b` since this is the binary representation of `20`. Feel free to try out other values.

Next, make a new assembly procedure by adding this code under the existing code in `Assembly.asm`:
```
anotherProcedure:
	mov eax, edi
	add eax, esi
	ret
```
At the top of this file, you will need to add this line:
```
global anotherProcedure
```
Also, in `Main.c` add the header:
```
int anotherProcedure(int,int);
```
and add this code at the end of the `main` function:
```
printf("Result: %d\n", anotherProcedure(result1,result2));
```
Running the code at this point will produce this output:
```
Result: 150
```
The reason is that the code adds its two `int` parameters and returns the result. The two `int` parameters are explicitly passed via the registers `edi` and `esi`. More information on C parameter passing convention is available via links on Moodle.

Now you will define a simple procedure with conditional statements (if-statements). Copy the following code into your assembly program, and then add the other code needed to both the assembly and C files in order to execute the code from the C program. Here is the assembly procedure (note that comments start with a semi-colon `;`):
```
; Three int parameters sent via edi, esi, and edx. 
; Return the maximum of the three parameters in eax.
maxOfThree:
    cmp edi, esi
    jg ediBiggerThanESI ; jump if edi > esi
esiBiggerThanEDI:       ; technically esi >= edi
    cmp esi, edx
    jg esiBiggest       ; jump if esi > edx (already know that esi >= edi)
    jmp edxBiggest      ; edx >= esi and esi >= edi, so edx is biggest
ediBiggerThanESI:
    cmp edi, edx
    jg ediBiggest       ; jump if edi > edx (already know that edi > esi)
    jmp edxBiggest      ; edx >= edi and edi > esi, so edx is biggest
ediBiggest:
    mov eax, edi
    jmp exitMaxOfThree  ; Skip remaining code to return result
esiBiggest:
    mov eax, esi
    jmp exitMaxOfThree  ; Skip remaining code to return result
edxBiggest:
    mov eax, edx        ; No need for jmp after this. Already at the end.
exitMaxOfThree:
    ret     ; eax now contains maximum of edi, esi, and edx
```
Be sure to thoroughly test this function from the C code.

The last assembly example you will be coding adds up the sum of numbers from 1 to some parameter value. Here is the assembly code:
```
; One int parameter in edi.
; Return the sum of the numbers from 1 to edi in eax.
sum1toN:
    mov ecx, 1      ; loop counter ecx = 1
    mov eax, 0      ; accumulator eax = 0
sumLoopStart:
    cmp ecx, edi    
    jg endSumLoop       ; If ecx > edi then return result
    add eax, ecx        ; Accumulate result: eax += ecx
    inc ecx             ; increment loop counter: ecx++
    jmp sumLoopStart    ; Return to loop start to test termination condition
endSumLoop:
    ret
```
After adding this code to your assembly file, add whatever other code it necessary to call and test the function with various values.

# Team Activity File Reading and Analyzing Assembly

This lab seeks to help you understand File I/O in c, along with seeing the basic assembly that is generated for programs before it goes into a binary form.

For this team activity, you will have multiple small programs to write. The goals for this team activity are as follows:
* Better understand command line program arguments
* Better understand reading files in c
* Better understand the assembly generated for a program, and the cost of various commands

## :star: Working in Teams :star:
When working in teams, remember do not let one person do all the work. Make sure to work together, and ask questions. It is also better if different people program, and you all take turns programming for various team assignments. 



## Program Arguments
Programs, especially command line programs, have arguments that are passed into them, and based on those arguments it changes how the program runs.  For example, 

* `ls -l` on the linux / macOS command line will list the files in the current directory in a long format. 
* `gcc -g -Wall my_file.c -o my_file.out` will compile the file my_file.c into an executable called my_file.out

Everything after the program name, is an argument!  

In c programming, you will notice the main function as two optional arguments

```c
#include <stdio.h>
#include <string.h>


int main(int argc, char const *argv[]) {
    printf("Number of arguments is: %d\n", argc);
    printf("Arguments: \n");
    for(int i=0; i < argc; i++) {
        printf("The argv[%d] = %s\n", i, argv[i]); 
    printf("\n");
    }
    return 0;
    
}
```

* argc - is the argument count. This is the number of arguments passed into the program. It is always at least 1
* argv - is an array of strings. Each string is an argument passed into the program. The first argument is always the program name.


👉🏽 **Your Task**  Write a program that prints out all of the arguments passed into it. Make it so at least one argument is passed into it. 

### Discussion
* What is the first argument passed into the program?

  * The first arg is always the program name

* Why would having program arguments be useful for programs?

  * Test modular code, one arg at a time, with print statments to show outputs line-by-line
  * Create structure to follow, for setting up future code
  * Can help reduce the amount of coding
  * Increases fluidity, without having as much hard code

## Reading a File
If you followed Mike Shaw's video, you will have a good idea of how to read a file. This follows a similar guideline. 

The standard c library stdlib provides a number of File access functions.  If you wanted to open a file using the first 
program argument, you could do it the following way

```c
FILE *input = fopen(argv[1],"r");
```

```c
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



#define BUFF_SIZE 1024

int main(int argc, char const *argv[])
{

FILE *input = fopen(argv[1],"r");
char* line = malloc(BUFF_SIZE * sizeof(char));
while (fgets(line, BUFF_SIZE, input) != NULL) {
    // do the thing, line now has the line from input
    printf("%s",line);
}

free(line); // don't forget to free memory!
fclose(input); // don't forget to close a file!

return 0;
}
```

👉🏽 **Your Task**  Read the file with the name passed in via program arguments, and print out its contents to the screen 


## Generating Assembly Files 

Both gcc and clang allow you to generate the assembly file for their code.  Looking at [simple.c], we see a program that
simply adds two numbers, and then ends. However, [simple.s] is the assembly built from this program. This was done using the following option.

> gcc -S simple.c

👉🏽 **Your Task** Generate the assembly code for the programs you just wrote by using the -S option.

arg_practice.s:
```
.file	"arg_practice.c"
	.text
	.section	.rodata
.LC0:
	.string	"Number of arguments is: %d\n"
.LC1:
	.string	"Arguments: "
.LC2:
	.string	"The argv[%d] = %s\n"
	.text
	.globl	main
	.type	main, @function
main:
.LFB0:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movl	-20(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC0(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	leaq	.LC1(%rip), %rax
	movq	%rax, %rdi
	call	puts@PLT
	movl	$0, -4(%rbp)
	jmp	.L2
.L3:
	movl	-4(%rbp), %eax
	cltq
	leaq	0(,%rax,8), %rdx
	movq	-32(%rbp), %rax
	addq	%rdx, %rax
	movq	(%rax), %rdx
	movl	-4(%rbp), %eax
	movl	%eax, %esi
	leaq	.LC2(%rip), %rax
	movq	%rax, %rdi
	movl	$0, %eax
	call	printf@PLT
	movl	$10, %edi
	call	putchar@PLT
	addl	$1, -4(%rbp)
.L2:
	movl	-4(%rbp), %eax
	cmpl	-20(%rbp), %eax
	jl	.L3
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE0:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
```

file_reading_practice.s
```
	.file	"file_reading_practice.c"
	.text
	.section	.rodata
.LC0:
	.string	"r"
	.text
	.globl	main
	.type	main, @function
main:
.LFB6:
	.cfi_startproc
	endbr64
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset 6, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register 6
	subq	$32, %rsp
	movl	%edi, -20(%rbp)
	movq	%rsi, -32(%rbp)
	movq	-32(%rbp), %rax
	addq	$8, %rax
	movq	(%rax), %rax
	leaq	.LC0(%rip), %rdx
	movq	%rdx, %rsi
	movq	%rax, %rdi
	call	fopen@PLT
	movq	%rax, -16(%rbp)
	movl	$1024, %edi
	call	malloc@PLT
	movq	%rax, -8(%rbp)
	jmp	.L2
.L3:
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	puts@PLT
.L2:
	movq	-16(%rbp), %rdx
	movq	-8(%rbp), %rax
	movl	$1024, %esi
	movq	%rax, %rdi
	call	fgets@PLT
	testq	%rax, %rax
	jne	.L3
	movq	-8(%rbp), %rax
	movq	%rax, %rdi
	call	free@PLT
	movq	-16(%rbp), %rax
	movq	%rax, %rdi
	call	fclose@PLT
	movl	$0, %eax
	leave
	.cfi_def_cfa 7, 8
	ret
	.cfi_endproc
.LFE6:
	.size	main, .-main
	.ident	"GCC: (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0"
	.section	.note.GNU-stack,"",@progbits
	.section	.note.gnu.property,"a"
	.align 8
	.long	1f - 0f
	.long	4f - 1f
	.long	5
0:
	.string	"GNU"
1:
	.align 8
	.long	0xc0000002
	.long	3f - 2f
2:
	.long	0x3
3:
	.align 8
4:
```

### Discussion
* What are some of the assembly commands generated?
  * pushq, popq, movl, call, ret
  
* Was there more than you expected?
  * Yes

* If you run `gcc -S shift.c`. Do you notice anything unusual about the generated assembly? (alright if you don't.. will cover it below)
  * We did not

## Finishing Estimator
Estimator is a program that helps estimate the total number of processor cycles for a program to run. This can be helpful when comparing the costs of various operations in your program (though it is very loosely done).

Go ahead and use [estimator.c] for your template. You will notice the skeleton is implemented, but you will need to complete the `run_program` function


👉🏽 **Your Task**  Go ahead and finish the `run_program` function.

```
void run_program(char* file_name) {
    // student TODO
    int * counts = calloc(11, sizeof(int));
    FILE *input = fopen(file_name,"r");
    char* line = malloc(BUFF_SIZE * sizeof(char));
    while (fgets(line, BUFF_SIZE, input) != NULL) {
        convertToUpperCase(line);
        for (int i = 0; i < 11; i++)
        {
            if (contains(line,instructions[i]))
            {
                counts[i]++;
            }
        }
        // do the thing, line now has the line from input
        // printf("%s",line);
    }
    
    print_info(counts);
    free(line); // don't forget to free memory!
    free(counts);
    fclose(input); // don't forget to close a file!
}
```

### Discussion
* What were some challenges?
  * understanding the multidimensional array and looping through correctly
  * Reading in the files without defining them ahead of time (not sure why, my brain wants to see the name beforehand)
  
  
* What do the cycles tell you about the difficulty of the process for the computer?
  * It looks like some cycles are more expensive or difficult for the computer than others

* Why does this/knowing assembly matter?
  * This right here is the hard one. It can be difficult to see the forest through the trees, so discuss some reasons that come to mind and share them with the class at the end.

* Without understanding assembly, it is harder to optimize the run time of programs
* Can be helpful with niche errors and debugging in general

* If you have time, use the Godbolt tool (linked below) to try equivalent programs in various languages. 
  * How does python and c differ, even if it the code is "equivalent"?
  
* We did not have time for this exploration

## Diving Into Optimization

As a quick reminder, there is a the `shift` operators in most languages. The left and right shift operators are `<<` and `>>` respectively. These operators shift the bits of a number left or right. For example, `5 << 1` is `10` and `10 >> 1` is `5`.

Go ahead and compile shift.c, and run the program. For example

```bash
gcc shift.c -o shift.out
./shift.out 10
```

Notice all three statements are equivalent! However, if you look at the assembly generated, you will notice that the first two are the same, but the third is different. Why do you think this is? Compilers will try to optimize their code, and since the cycle costs of MUL is more than SHL, it will try to use SHL when possible.

:star: Go ahead and run your estimator on shift.s. Take a look at the total cycle cost. :star:

Important - before this next step, you will want to backup your shift.s file. You can do this by running the following command

```bash
cp shift.s shift.s.bak
```

### Optimization Level 3
A good compiler will go even farther. Try the following compile command.

```bash
gcc shift.c -S -O3
```

That is the letter O, not the number 0. This will compile the code with the highest level of optimization. Now look at the assembly generated. Notice how it is different than the previous assembly generated.

:star: Go ahead and run your estimator on shift.s. Take a look at the total cycle cost. :star:

### Discussion
* How did the total cycle costs of the program change? When setting up this team activity, it was a substantial difference! 


## Technical Interview Practice

As per our standard end of the team activity - go to the Module 02 challenge problems, and as a group pick a couple to work on. Discuss your solutions. Include a solution in your team activity meeting files. You are also encouraged to take a technical interview question and discuss solutions as a group.  

* Judson - "Hello World!" in C
* Tor - Sum and difference
* Umer - Two sum
* Daymian - Squares of a sorted array

## 📚 Resources

* [strstr() tutorial](https://www.tutorialspoint.com/c_standard_library/c_function_strstr.htm)
* [CString reference](https://cplusplus.com/reference/cstring/)
* [Compiler Explorer](https://godbolt.org/) - really neat tool to explore compiled code
* [Guide to Cycle Costs](https://www.agner.org/optimize/instruction_tables.pdf)


[simple.c]: simple.c
[simple.s]: simple.s
[estimator.c]: estimator.c
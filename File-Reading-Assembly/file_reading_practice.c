#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//for reference
// int main(int argc, char const *argv[]) {
//     printf("Number of arguments is: %d\n", argc);
//     printf("Arguments: \n");
//     for(int i=0; i < argc; i++) {
//         printf("The argv[%d] = %s\n", i, argv[i]); 
//     printf("\n");
//     }
//     return 0;
    
// }


// ```c
// char buff[BUFF_SIZE]; 

// FILE *input = fopen(argv[1],"r");
// char* line = malloc(BUFF_SIZE * sizeof(char));
// while (fgets(line, BUFF_SIZE, input) != NULL) {
//     // do the thing, line now has the line from input
    
// }

// free(line); // don't forget to free memory!
// fclose(input); // don't forget to close a file!
// ```


#define BUFF_SIZE 1024

int main(int argc, char const *argv[])
{
char buff[BUFF_SIZE]; 

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
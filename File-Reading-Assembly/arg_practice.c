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
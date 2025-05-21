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
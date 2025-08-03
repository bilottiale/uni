#include <stdio.h>
#include <stdlib.h>
 
#define  MAX_LEN  128

int main(void)
{
   FILE *stream;
   char line[MAX_LEN], *result;
 
    printf("Insert a string [Enter to terminate the string; Ctrl+D to exit the program]:\n");
    if ((result = fgets(line,MAX_LEN,stdin)) != NULL)
        printf("The string is %s\n", result);
    else
        perror("fget error");

   // Read from file
   // Compile it to test read from file
#if 1
   if ((stream = fopen("file.txt","rb")) == NULL){
      perror("file.txt not found");
      exit(1);
   }

   if ((result = fgets(line,MAX_LEN,stream)) != NULL)
      printf("The string is %s\n", result);
   else
      perror("fget error");
 
   if (fclose(stream))
      perror("fclose error");
#endif

   return 0;
}

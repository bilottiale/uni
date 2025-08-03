#include <stdlib.h>
#include <stdio.h>
 
int main(void)
{
   char *string, *stopstring;
   long l;
   int bs;
 
   string = "10110134932";
   printf("string = %s\n", string);
   l = strtol(string, &stopstring, 0);
   printf("   strtol = %ld (base %d)\n", l, 0);
   printf("   Stopped scan at %s\n\n", stopstring);
   for (bs = 2; bs <= 8; bs *= 2)
   {
      l = strtol(string, &stopstring, bs);
      printf("   strtol = %ld (base %d)\n", l, bs);
      printf("   Stopped scan at %s\n\n", stopstring);
   }

   return 0;
}

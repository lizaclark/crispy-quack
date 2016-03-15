#include <stdio.h>
/* This program will return endianness of
 * current machine. Copied from http://www.geeksforgeeks.org/little-and-big-endian-mystery/ */ 
int main()
{
   unsigned int i = 1;
   char *c = (char*)&i;
   if (*c)   
       printf("Little endian");
   else
       printf("Big endian");
   getchar();
   return 0;
}

#include <stdio.h>

int main()
{
  printf("size_t: %zd\n",sizeof(size_t));
  printf("float: %zd\n",sizeof(float));
  printf("short int: %zd\n",sizeof(short int));
  printf("unsigned short int: %zd\n",sizeof(unsigned short int));
  printf("int: %zd\n",sizeof(int));
  printf("char: %zd\n",sizeof(char));
  printf("trying: %zd\n",(((size_t)-1)>>1));
  return(0);
}

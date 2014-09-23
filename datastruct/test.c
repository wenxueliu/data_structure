#include <stdlib.h>

#define X 3
#define Y X*2
#undef  X
#define X 2

int main(void)
{
  int x = -5;
  
  printf("the a is%d,%d, %d\n",x,x<<2,x>>2); 
  return 0;
}

#include <stdio.h>

int main() {
  // Your code here
  struct Test {
    char *s;
    unsigned short b;
    int res;
    int num;
  };


  int i;
  i = stoub(t.s, t.b, &j);
  if (i != t.res || (i == 1 && j != t.num)) printf("TEST FAILED! expecting (%d,%d), got (%d,%d)\n",t.res,t.num,i,j);
  else printf("TEST PASSED!\n");
  return 0;
}

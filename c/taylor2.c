//implements taylor's expansion using iterative process

#include<stdio.h>
double e(int x, int n) {
  double s;
  for(;n > 0; n--)
    s= 1+x*s/n;
  return s;
}

int main(void) {
  printf("%lf \n", e(1, 12));
  return 0;
}

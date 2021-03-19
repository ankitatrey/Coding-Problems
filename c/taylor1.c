//implements talyor's series using horner's rule
#include<stdio.h>

double e(int x, int n) {
  static double s=1;
  if (n == 0) return s;
  s = 1 + x*s/n;
  return e(x, n-1);

}

int main(void) {
  printf("%lf \n", e(1,12));
  return 0;
}

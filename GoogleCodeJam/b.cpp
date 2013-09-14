#include <stdio.h>
#include <math.h>

#define PI (3.141592653)
int main()
{
  int t;
  int v;
  int d;
  scanf("%d", &t);
  for (int i = 1; i <= t; i++) {
    scanf("%d %d", &v, &d);
    double sin2 = 9.8*d/(v*v);
    double angle = 90.0*asin(sin2)/PI;
    printf("Case #%d: %.7lf\n", i, angle);
  }
}

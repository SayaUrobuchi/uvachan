#include <stdio.h>

int main()
{
  int n, max;
  while(scanf("%d", &n)==1)
  {
    max=n;
    while(n>2)
    {
      max+=n/3;
      n=n/3+n%3;
    }
    if(n==2) max++;
    printf("%d\n", max);
  }
  return 0;
}

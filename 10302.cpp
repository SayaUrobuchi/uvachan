#include<stdio.h>
int main()
{
    long long int x,a;
    while(scanf("%lld",&a)==1)
    {
        a=(a+1)*a/2;
        x=a*a;
        printf("%lld\n",x);
    }
    return 0;
}

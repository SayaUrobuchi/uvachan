#include<stdio.h>
#include<math.h>
int main()
{
    long long int a,b;
    while(scanf("%lld",&a)==1)
    {
        if(a==0)
        {
            break;
        }
        b=(long long int)(sqrt(a));
        b*=b;
        if(a==b)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }
    return 0;
}

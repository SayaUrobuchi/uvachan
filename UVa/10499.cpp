#include<stdio.h>
int main()
{
    long long int a;
    while(scanf("%lld",&a)==1)
    {
        if(a<0)
        {
            break;
        }
        if(a==1)
        {
            printf("0%c\n",37);
        }
        else
        {
            printf("%lld%c\n",a*25,37);
        }
    }
    return 0;
}

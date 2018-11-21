#include<stdio.h>
int main()
{
    long long int a,b,c,d,e,f;
    while(scanf("%lld",&a)==1)
    {
        if(a==-1)
        {
            break;
        }
        if(a==0)
        {
            printf("0 1\n");
        }
        else
        {
            for(b=0,c=1,f=0;f<a;f++)
            {
                d=b+c+1;
                b=c;
                c=d;
            }
            printf("%lld %lld\n",b,c);
        }
    }
    return 0;
}

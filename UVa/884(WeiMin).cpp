#include <stdio.h>
#include <math.h>
int a[1000000];
int main()
{
    int b,c,d,e;
    a[0]=0;
    a[1]=1;
    for(b=2;b<=1000000;b++)
    {
        c=b;
        e=sqrt(c);
        for(d=2;d<=e;d++)
        {
            if(c%d==0)
            {
                c=c/d;
                a[b-1]=a[b-2]+a[c-1]-a[c-2]+1;
                goto haha;
            }
        }
        a[b-1]=a[b-2]+1;
        haha:;
    }
    while(scanf("%d",&b)==1)
    {
        printf("%d\n",a[b-1]);
    }
    return 0;
}

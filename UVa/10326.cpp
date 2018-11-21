#include<stdio.h>
int main()
{
    long long int c,k[51];
    int a,b,d;
    while(scanf("%d",&a)==1)
    {
        k[0]=0;
        for(b=0;b<a;b++)
        {
            scanf("%lld",&c);
            c*=-1;
            k[b]=1;
            for(d=b;d>0;d--)
            {
                k[d]*=c;
                k[d]+=k[d-1];
            }
            k[0]*=c;
        }
        k[a]=1;
        for(b=a;b>0;b--)
        {
            if(k[b]!=0)
            {
                if(b!=a)
                {
                    if(k[b]<0)
                    {
                        printf(" - ");
                    }
                    else
                    {
                        printf(" + ");
                    }
                }
                if(k[b]!=1&&k[b]!=-1)
                {
                    if(k[b]<0)
                    {
                        k[b]*=-1;
                    }
                    printf("%lld",k[b]);
                }
                if(b!=1)
                {
                    printf("x^%d",b);
                }
                else
                {
                    printf("x");
                }
            }
        }
        if(k[0]>=0)
        {
            printf(" + %lld = 0\n",k[0]);
        }
        else
        {
            k[0]*=-1;
            printf(" - %lld = 0\n",k[0]);
        }
    }
    return 0;
}

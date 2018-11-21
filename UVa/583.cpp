#include<stdio.h>
#include<math.h>
int main()
{
    int a,b,c,d,e,f,g;
    while(scanf("%d",&a)==1)
    {
        if(a==0)
        {
            break;
        }
        printf("%d = ",a);
        d=0;
        if(a<0)
        {
            printf("-1");
            a*=-1;
            d=1;
        }
        for(b=1,c=a,e=(int)(sqrt(a));b<e+1;b+=2)
        {
            if(b>c)
            {
                break;
            }
            if(b==1)
            {
                if(c%2==0)
                {
                    if(d>0)
                    {
                        printf(" x ");
                    }
                    printf("2");
                    d=2;
                    c/=2;
                    b-=2;
                }
            }
            else
            {
                if(c%b==0)
                {
                    if(d>0)
                    {
                        printf(" x ");
                    }
                    printf("%d",b);
                    d=2;
                    c/=b;
                    b-=2;
                }
            }
        }
        if(c!=1)
        {
            if(d>0)
            {
                printf(" x ");
            }
            printf("%d",c);
        }
        printf("\n");
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int a[200],b,c,d,e,f;
    while(scanf("%d",&b)==1)
    {
        for(c=b+1,f=0;c<=b*2;c++)
        {
            d=c*b;
            e=c-b;
            if(d%e==0)
            {
                a[f]=c;
                f++;
            }
        }
        printf("%d\n",f);
        for(c=0;c<f;c++)
        {
            printf("1/%d = 1/%d + 1/%d\n",b,a[c]*b/(a[c]-b),a[c]);
        }
    }
    return 0;
}

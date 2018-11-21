#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k[10000];
    h=0;
    while(scanf("%d %d %d %d",&a,&b,&c,&d)==4)
    {
        if(a==0&&b==0&&c==0&&d==0)
        {
            break;
        }
        h++;
        for(i=0;i<10000;i++)
        {
            k[i]=0;
        }
        for(i=1;i<10000;i++)
        {
            j=d*a+b;
            j%=c;
            if(k[j]!=0)
            {
                printf("Case %d: %d\n",h,i-k[j]);
                break;
            }
            k[j]=i;
            d=j;
        }
    }
    return 0;
}

#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k,l[]={6,2,4,8};
    while(scanf("%d%d",&a,&b)==2)
    {
        for(c=0,d=1,i=0,j=0;c<b;c++,a--)
        {
            e=a;
            if(!(e%2))
            {
                while(!(e%2))
                {
                    i++;
                    e/=2;
                }
            }
            if(!(e%5))
            {
                while(!(e%5))
                {
                    j++;
                    e/=5;
				}
            }
            d*=e%10;
            d%=10;
        }
        if(i>j)
        {
            i-=j;
            d*=l[i%4];
            d%=10;
        }
        else if(i<j)
        {
            d*=5;
            d%=10;
        }
        printf("%d\n",d);
    }
    return 0;
}
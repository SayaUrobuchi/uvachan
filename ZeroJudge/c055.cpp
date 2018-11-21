#include<stdio.h>
int main()
{
    int a,b,c,d,e,f,g,h,i,j,k[10001];
    while(scanf("%d",&a)==1)
    {
        if(a==0)
        {
            printf("    0 -> 1\n");
        }
        else if(a==1)
        {
            printf("    1 -> 1\n");
        }
        else
        {
            for(b=2,c=1,d=0;b<=a;b++)
            {
                e=b;
                if(e%2==0)
                {
                    for(f=0;f>=0;f++)
                    {
                        e/=2;
                        d++;
                        if(e%2==1)
                        {
                            break;
                        }
                    }
                }
                if(e%5==0)
                {
                    for(f=0;f>=0;f++)
                    {
                        e/=5;
                        d--;
                        if(e%5!=0)
                        {
                            break;
                        }
                    }
                }
                c*=e;
                c%=10;
            }
            d%=4;
            if(d==0)
            {
                c*=6;
                c%=10;
            }
            else if(d==1)
            {
                c*=2;
                c%=10;
            }
            else if(d==2)
            {
                c*=4;
                c%=10;
            }
            else
            {
                c*=8;
                c%=10;
            }
            printf("%5d -> %d\n",a,c);
        }
    }
    return 0;
}

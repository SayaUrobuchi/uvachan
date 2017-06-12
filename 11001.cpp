#include<stdio.h>
#include<math.h>
int main()
{
    double m,x,y;
    int a,b,c,i,j;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(a==0&&b==0)
        {
            break;
        }
        /*for(c=a/(2*b)-1,y=0,j=0;c<a;c++)
        {
            if(c==0)
            {
                c=1;
            }
            m=a;
            m/=c;
            if(m<=b)
            {
                printf("0\n");
                break;
            }
            else
            {
                x=m;
                x-=b;
                x=sqrt(x);
                x*=0.3;
                x*=c;
                if(x>y)
                {
                    y=x;
                }
                else if(x==y)
                {
                    printf("0\n");
                    break;
                }
                else
                {
                    printf("%d\n",c-1);
                    break;
                }
            }
        }*/
        x=a;
        x/=2*b;
        if(x!=(int)(x)&&x*2==(int)(x*2))
        {
            printf("0\n");
        }
        else
        {
            printf("%.0f\n",x);
        }
    }
    return 0;
}

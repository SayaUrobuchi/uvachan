#include<stdio.h>
int main()
{
    double a,b,c,d,i,j,k,x,y;
    int e,f,g,h;
    while(scanf("%lf %lf %lf %lf",&a,&b,&c,&d)==4)
    {
        if(a==0&&b==0&&c==0&&d==0)
        {
            break;
        }
        for(e=1,x=0,y=b;e>0;e++)
        {
            x+=y;
            if(x>a)
            {
                printf("success on day %d\n",e);
                break;
            }
            else if(x<0)
            {
                printf("failure on day %d\n",e);
                break;
            }
            y-=b*d/100;
            if(y<0)
            {
                y=0;
            }
            //printf("%f\n",y);
            x-=c;
            if(x<0)
            {
                printf("failure on day %d\n",e);
                break;
            }
            //printf("%f\n",x);
        }
    }
    return 0;
}

#include<stdio.h>
int main()
{
    double x,y;
    int a,b,c,d,e,f,g,h,i,j,k;
    while(scanf("%d %d",&a,&b)==2)
    {
        if(a==0&&b==0)
        {
            break;
        }
        c=a-b;
        if(c>b)
        {
            for(d=c+1,x=1;d<=a;d++)
            {
                x*=d;
            }
            for(d=1,y=1;d<=b;d++)
            {
                y*=d;
            }
            x/=y;
            printf("%.0f\n",x);
        }
        else
        {
            for(d=b+1,x=1;d<=a;d++)
            {
                x*=d;
            }
            for(d=1,y=1;d<=c;d++)
            {
                y*=d;
            }
            x/=y;
            printf("%.0f\n",x);
        }
    }
    return 0;
}

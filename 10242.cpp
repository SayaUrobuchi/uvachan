#include<stdio.h>
int main()
{
    double a[8],b,c,d;
    int e,f,g,h;
    while(scanf("%lf",&a[0])==1)
    {
        for(e=1;e<8;e++)
        {
            scanf("%lf",&a[e]);
        }
        if(a[0]==a[4]&&a[1]==a[5])
        {
            printf("%.3f %.3f\n",a[2]-a[0]+a[6],a[3]-a[1]+a[7]);
        }
        else
        {
            if(a[0]==a[6]&&a[1]==a[7])
            {
                printf("%.3f %.3f\n",a[2]-a[0]+a[4],a[3]-a[1]+a[5]);
            }
            else
            {
                if(a[2]==a[4]&&a[3]==a[5])
                {
                    printf("%.3f %.3f\n",a[6]-a[2]+a[0],a[7]+a[1]-a[3]);
                }
                else
                {
                    printf("%.3f %.3f\n",a[4]-a[2]+a[0],a[5]+a[1]-a[3]);
                }
            }
        }
    }
    return 0;
}

#include<stdio.h>
int main()
{
    double a[10][5],h,i,j,k;
	int e,g=0,f,b,d;
    char c;
    for(d=0;d<11;d++)
    {
        scanf("%c",&c);
        if(c==114&&d<10)
        {
            for(b=0;b<4;b++)
            {
                scanf("%lf",&a[d][b]);
            }
            a[d][4]=1;
        }
        else if(c==99&&d<10)
        {
            for(b=0;b<3;b++)
            {
                scanf("%lf",&a[d][b]);
            }
            a[d][4]=2;
        }
        else if(c==42)
        {
            break;
        }
		else
		{
			d--;
		}
    }

    f=d;
    while(scanf("%lf %lf",&h,&i)==2)
    {
        g++;
        if(h==9999.9&&i==9999.9)
        {
            break;
        }
        else
        {
            for(e=0;e<f;e++)
            {
                if(a[e][4]==1)
                {
                    if(h>a[e][0]&&h<a[e][2]&&i<a[e][1]&&i>a[e][3])
                    {
                        b=1;
                        printf("Point %d is contained in figure %d\n",g,e+1);
                    }
                }
                else
                {
                    j=h-a[e][0];
                    j*=j;
                    k=i-a[e][1];
                    k*=k;
                    j+=k;
                    k=a[e][2]*a[e][2];
                    if(j<k)
                    {
                        b=1;
                        printf("Point %d is contained in figure %d\n",g,e+1);
                    }
                }
            }
            if(b!=1)
            {
                printf("Point %d is not contained in any figure\n",g);
            }
			b=0;
        }
    }
    return 0;
}

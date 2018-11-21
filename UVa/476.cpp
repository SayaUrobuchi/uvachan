#include<stdio.h>
int main()
{
    double a[10][4];
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
	double h,i;
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
                if(h>a[e][0]&&h<a[e][2]&&i<a[e][1]&&i>a[e][3])
                {
                    b=1;
                    printf("Point %d is contained in figure %d\n",g,e+1);
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

#include<stdio.h>
int main()
{
    double x[6001],y;
    int a,b,c,d,e,f,g,h,i,j,k[]={2,4,10,20,40,100,200,400,1000,2000};
    for(a=0;a<6001;a++)
    {
        x[a]=1;
    }
    for(a=0;a<10;a++)
    {
        for(b=0;b<6001-k[a];b++)
        {
            x[b+k[a]]+=x[b];
        }
    }
    while(scanf("%lf",&y)==1)
    {
        if(y==0)
        {
            break;
        }
        a=(int)(y*20+0.5);
        printf("%6.2f%17.0f\n",y,x[a]);
    }
	return 0;
}

#include<stdio.h>
int main()
{
	int a,b,c,d,e,f,g;
	double h,i,j,k,w,x,y,z;
	while(scanf("%d",&g)==1)
	{
		a=0;
		scanf("%lf %lf %lf %lf",&h,&i,&j,&k);
		for(g;g>0;g--)
		{
			scanf("%lf %lf",&w,&x);
			if(a==0)
			{
				y=w-h;
				y*=y;
				y+=(x-i)*(x-i);
				z=w-j;
				z*=z;
				z+=(x-k)*(x-k);
				if(y*4<=z)
				{
					printf("The gopher can escape through the hole at (%.3f,%.3f).\n",w,x);
					a=1;
				}
			}
		}
		if(a==0)
		{
			printf("The gopher cannot escape.\n");
		}
	}
	return 0;
}
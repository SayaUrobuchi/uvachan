#include<stdio.h>
#include<math.h>
int main()
{
	double f[4],i,j,x,y;
	int a,b,c,d,e;
	while(scanf("%d %d",&a,&b)==2)
	{
		if(a==0&&b==0)
		{
			break;
		}
		e=b*b;
		for(c=0,d=0;c<a;c++)
		{
			scanf("%lf %lf",&i,&j);
			f[0]=i*i;
			f[1]=b-i;
			f[1]*=f[1];
			f[2]=j*j;
			f[3]=b-j;
			f[3]*=f[3];
			x=f[0]+f[2];
			if(x>e)
			{
				continue;
			}
			x=f[0]+f[3];
			if(x>e)
			{
				continue;
			}
			x=f[1]+f[2];
			if(x>e)
			{
				continue;
			}
			x=f[1]+f[3];
			if(x>e)
			{
				continue;
			}
			d++;
		}
		x=d;
		x/=a;
		x*=e;
		printf("%.5f\n",x);
	}
	return 0;
}
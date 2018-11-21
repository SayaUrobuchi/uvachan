#include<stdio.h>
#include<math.h>
int main()
{
	int a;
	double x;
	long long b,c;
	while(scanf("%d%lld",&a,&b)==2)
	{
		x=0;
		x-=2*a+1;
		x+=sqrt(x*x-8*a+8*b);
		x/=2;
		c=x;
		if(c!=x)
		{
			c++;
		}
		printf("%lld\n",c+a);
	}
	return 0;
}
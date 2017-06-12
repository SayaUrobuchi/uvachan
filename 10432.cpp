#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,i,j,x,y;
	i=2.0*acos(0.0);
	while(scanf("%lf %lf",&a,&b)==2)
	{
		j=a*sin(i/b);
		y=a*a-j*j;
		x=sqrt(y);
		x*=j;
		x*=b;
		printf("%.3f\n",x);
	}
	return 0;
}
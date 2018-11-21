#include<stdio.h>
#include<math.h>
int main()
{
	int n,d,l;
	double i,j,pi;
	pi=2.0*acos(0);
	scanf("%d",&n);
	while(n--)
	{
		scanf("%d%d",&d,&l);
		i=l*l/4.0;
		i-=d*d/4.0;
		i=sqrt(i);
		i*=l*pi/2.0;
		printf("%.3f\n",i);
	}
	return 0;
}
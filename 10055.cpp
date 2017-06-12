#include <stdio.h>
int main()
{
	double a,b;
	while(scanf("%lf %lf",&a,&b)==2)
	{
		a=a-b;
		if(a<0)
		{
			a=a*(-1);
		}
		printf("%.0f\n",a);
	}
	return 0;
}

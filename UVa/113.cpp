#include<stdio.h>
#include<math.h>
int main()
{
	double x,y,z;
	while(scanf("%lf %lf",&x,&y)==2)
	{
		z=pow(y,1/x)+0.001;
		printf("%.0f\n",z);
	}
	return 0;
}
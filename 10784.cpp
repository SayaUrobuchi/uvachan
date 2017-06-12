#include<stdio.h>
#include<math.h>
int main()
{
	double a,b;
	int h;
	h=0;
	while(scanf("%lf",&a)==1)
	{
		if(a==0)
		{
			break;
		}
		b=(int)ceil((3.0+sqrt(9.0+8.0*a))/2.0-1e-10);
		h++;
		printf("Case %d: %.0f\n",h,b);
	}
	return 0;
}
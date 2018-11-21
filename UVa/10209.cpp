#include<stdio.h>
#include<math.h>
int main()
{
	double a,b,c,d,g,h;
	g=sqrt(3);
	h=2.0*acos(0.0);
	while(scanf("%lf",&a)==1)
	{
		b=a;
		b*=b;
		b/=12;
		b*=h;
		c=g*a/2;
		c-=a/2;
		c*=a/2;
		b-=c;
		b*=4;
		printf("%.3f",b);
		c=a*a*h/2;
		c-=a*a;
		c*=2;
		c-=b*2;
		printf(" %.3f",c);
		c+=b;
		d=a*a;
		d-=c;
		printf(" %.3f\n",d);
	}
	return 0;
}
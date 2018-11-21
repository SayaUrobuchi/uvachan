#include <stdio.h>
#include <math.h>

int main()
{
	int i;
	double pi, x[3], y[3], ma[2][3], po[3][3], c, d, e, delta, r;
	pi=2.0*acos(0.0);
	while(scanf("%lf%lf", &x[0], &y[0])==2)
	{
		for(i=1; i<3; i++) scanf("%lf%lf", &x[i], &y[i]);
		for(i=0; i<3; i++)
		{
			po[i][0]=x[i]*x[i]+y[i]*y[i];
			po[i][1]=x[i];
			po[i][2]=y[i];
		}
		for(i=0; i<2; i++)
		{
			ma[i][0]=po[i][1]-po[i+1][1];
			ma[i][1]=po[i][2]-po[i+1][2];
			ma[i][2]=po[i+1][0]-po[i][0];
		}
		delta=ma[0][0]*ma[1][1]-ma[1][0]*ma[0][1];
		c=ma[0][2]*ma[1][1]-ma[1][2]*ma[0][1];
		c/=delta;
		d=ma[0][0]*ma[1][2]-ma[0][2]*ma[1][0];
		d/=delta;
		e=0-po[0][0];
		e-=c*x[0];
		e-=d*y[0];
		r=c*c/4+d*d/4-e;
		r=sqrt(r);
		r*=2*pi;
		printf("%.2f\n", r);
	}
	return 0;
}

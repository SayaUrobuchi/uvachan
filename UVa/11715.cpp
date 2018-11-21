#include <stdio.h>
#include <math.h>

int main()
{
	int cas, type;
	double v, a, s, u, t, x, y, z;
	cas = 0;
	/*
	v = u+at
	a = (v-u)/t
	s = vt+at^2/2
	t = (v-u)/a
	s = (u+at)t+a*t*t/2
	(.5a)t^2+ut-s = 0
	-u+sqrt(u^2-2as)/(1a)
	(-a/2)t^2+vt-s=0
	(-v+sqrt(v*v-2as)/-a
	If 1 u v t are given then print s and a
	If 2 u v a are given then print s and t
	If 3 u a s are given then print v and t
	If 4 v a s are given then print u and t
	*/
	while(scanf("%d%lf%lf%lf", &type, &x, &y, &z) == 4)
	{
		if(type == 1)
		{
			a = (y-x)/z;
			s = y*z-a*z*z/2;
			printf("Case %d: %.3lf %.3lf\n", ++cas, s, a);
		}
		else if(type == 2)
		{
			t = (y-x)/z;
			s = y*t-z*t*t/2;
			printf("Case %d: %.3lf %.3lf\n", ++cas, s, t);
		}
		else if(type == 3)
		{
			t = (-x+sqrt(x*x+2*y*z))/(1*y);
			v = x+y*t;
			printf("Case %d: %.3lf %.3lf\n", ++cas, v, t);
		}
		else if(type == 4)
		{
			t = (-x+sqrt(x*x-2*y*z))/(-y);
			u = x-y*t;
			printf("Case %d: %.3lf %.3lf\n", ++cas, u, t);
		}
	}
	return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
	double a, b, c, cosa, sina, mr, marea, s, tarea, sr, sarea, pi;
	pi = 2.0*acos(0.0);
	while(scanf("%lf%lf%lf", &a, &b, &c) == 3)
	{
		cosa = (double)(b*b+c*c-a*a) / (2*b*c);
		sina = sqrt(1.0 - cosa * cosa);
		mr = a / sina / 2;
		marea = mr * mr * pi;
		s = (a+b+c)/2;
		tarea = sqrt(s*(s-a)*(s-b)*(s-c));
		sr = (tarea+tarea) / (s+s);
		sarea = sr * sr * pi;
		printf("%.4lf %.4lf %.4lf\n", marea-tarea, tarea-sarea, sarea);
	}
	return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
	int count;
	double r1, r2, r3, v1, v2, v3, cos1, cos2, cos3, sin3, tarea;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lf%lf%lf", &r1, &r2, &r3);
		v1 = r2 + r3;
		v2 = r1 + r3;
		v3 = r1 + r2;
		cos1 = (v2*v2 + v3*v3 - v1*v1) / (2.0 * v2 * v3);
		cos2 = (v1*v1 + v3*v3 - v2*v2) / (2.0 * v1 * v3);
		cos3 = (v1*v1 + v2*v2 - v3*v3) / (2.0 * v1 * v2);
		sin3 = sqrt(1.0-cos3*cos3);
		tarea = v1 * v2 * sin3 / 2.0;
		tarea -= (r1 * r1 * acos(cos1) + r2 * r2 * acos(cos2) + r3 * r3 * acos(cos3)) / 2.0;
		printf("%.6lf\n", tarea);
	}
	return 0;
}

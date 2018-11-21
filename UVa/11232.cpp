#include <stdio.h>
#include <math.h>

int main()
{
	double pi, w, h, temp, temp2, ans;
	pi = 2.0 * acos(0.0);
	while(scanf("%lf%lf", &w, &h) == 2)
	{
		if(w == 0.0 && h == 0.0)
		{
			break;
		}
		if(w > h)
		{
			temp = w;
			w = h;
			h = temp;
		}
		temp = w / pi;
		ans = (h-temp) * temp * temp / 4 * pi;
		temp = h / (1.0 + 1.0 / pi);
		temp2 = temp / pi;
		if(temp2 > w)
		{
			temp2 = w;
		}
		temp = temp2 * temp2 / 4 * pi * w;
		if(temp > ans)
		{
			ans = temp;
		}
		printf("%.3f\n", ans);
	}
	return 0;
}

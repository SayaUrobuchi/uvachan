#include <stdio.h>

int main()
{
	int n, i, ans;
	double w, h, max, tmp;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		max = 0;
		for(i=0; i<n; i++)
		{
			scanf("%lf%lf", &w, &h);
			if(w > h)
			{
				tmp = w ;
				w = h;
				h = tmp;
			}
			h /= 4;
			if(h > w)
			{
				if(w > max)
				{
					max = w;
					ans = i;
				}
			}
			else
			{
				if(h > max)
				{
					max = h;
					ans = i;
				}
				w /= 2;
				if(w > max)
				{
					max = w;
					ans = i;
				}
			}
		}
		printf("%d\n", ans + 1);
	}
	return 0;
}

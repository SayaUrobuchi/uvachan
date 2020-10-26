#include <iostream>

int px[1024], py[1024];

int main()
{
	int n, i, j, t, u, ans, a, x, y;
	bool gg;
	while (scanf("%d%d", &px[0], &py[0]) == 2)
	{
		for (i=1; i<3; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
		}
		for (i=0, a=0; i<3; i++)
		{
			a += px[i]*py[(i+1)%3] - px[(i+1)%3]*py[i];
		}
		a = std::abs(a);
		scanf("%d", &n);
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d%d", &x, &y);
			j = 0;
			t = (px[j]-px[(j+2)%3])*(y-py[j]) - (py[j]-py[(j+2)%3])*(x-px[j]);
			if (t == 0)
			{
				if ((x >= px[j] && x <= px[(j+2)%3]) || (x >= px[(j+2)%3] && x <= px[j]))
				{
					++ans;
				}
			}
			else
			{
				for (j=1, gg=false; j<3; j++)
				{
					u = (px[j]-px[(j+2)%3])*(y-py[j]) - (py[j]-py[(j+2)%3])*(x-px[j]);
					if (u == 0)
					{
						gg = !((x >= px[j] && x <= px[(j+2)%3]) || (x >= px[(j+2)%3] && x <= px[j]));
						break;
					}
					else if ((u>0 && t<0) || (u<0 && t>0))
					{
						gg = true;
						break;
					}
				}
				if (!gg)
				{
					++ans;
				}
			}
		}
		printf("%d.%d\n", (a>>1), 5*(a&1));
		printf("%d\n", ans);
	}
	return 0;
}

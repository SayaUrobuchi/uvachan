#include <stdio.h>
#include <stdlib.h>

#define EPS 1e-4
#define STEP 1e-3

int b[50005], d[50005], a[50005], ptt[50005];

int comp(const void *p, const void *q)
{
	return b[*(int*)p] - b[*(int*)q];
}

double ab(double p)
{
	return p < 0 ? -p : p;
}

int eq(double p)
{
	return ab(p) < EPS;
}

double min(double p, double q)
{
	return p < q ? p : q;
}

int main()
{
	int count, n, i, h, w, p, sum, targ, maxh;
	double left, right, center, vol, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, maxh=0, sum=0; i<n; i++)
		{
			scanf("%d%d%d%d", &b[i], &d[i], &w, &h);
			sum += (a[i] = h * w) * d[i];
			ptt[i] = i;
			if(d[i] + b[i] > maxh)
			{
				maxh = d[i] + b[i];
			}
		}
		qsort(ptt, n, sizeof(int), comp);
		scanf("%d", &targ);
		if(targ > sum)
		{
			printf("OVERFLOW\n");
		}
		else
		{
			for(ans=0, left=0, right=10000000; left<right||eq(left-right); )
			{
				center = ((left + right) / 2.0);
				for(i=0, vol=0; i<n; i++)
				{
					p = ptt[i];
					if(center >= b[p])
					{
						vol += a[p] * (min(center, b[p]+d[p])-b[p]);
						if(vol > targ)
						{
							break;
						}
					}
					else
					{
						break;
					}
				}
				if(vol > targ || eq(vol-targ))
				{
					right = center - STEP;
					ans = center;
				}
				else
				{
					left = center + STEP;
				}
			}
			printf("%.2lf\n", ans);
		}
	}
	return 0;
}

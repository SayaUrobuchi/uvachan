#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int loc[10005], rad[10005], pp[10005];
double len[10005];

int comp(const void *p, const void *q)
{
	return loc[*(int*)p]-len[*(int*)p]>loc[*(int*)q]-len[*(int*)q]?1:-1;
}

int main()
{
	int i, j, n, l, ans;
	double last, mx, w;
	while(scanf("%d%d%lf", &n, &l, &w) == 3)
	{
		w /= 2;
		w *= w;
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &loc[i], &rad[i]);
			len[i] = sqrt(rad[i]*rad[i]-w>0?rad[i]*rad[i]-w:0);
			pp[i] = i;
		}
		qsort(pp, n, sizeof(int), comp);
		for(i=0, last=0, ans=0; i<n; )
		{
			for(j=i, mx=-1.0; j<n; j++)
			{
				if(loc[pp[j]]-len[pp[j]] > last)
				{
					break;
				}
				if(loc[pp[j]]+len[pp[j]] > mx)
				{
					mx = loc[pp[j]] + len[pp[j]];
				}
			}
			if(mx == -1.0)
			{
				break;
			}
			ans++;
			i = j;
			last = mx;
			if(last >= l)
			{
				break;
			}
		}
		if(mx == -1.0 || last < l)
		{
			printf("-1\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f[1050], used[1050];

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int ab(int p)
{
	return p < 0 ? -p : p;
}

int main()
{
	int count, n, m, i, j, dsp, csp, wsp, ans, open, on;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &dsp, &csp, &wsp);
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)
		{
			scanf("%d", &f[i]);
		}
		if(m == 0)
		{
			printf("0\n");
			continue;
		}
		qsort(f, m, sizeof(int), comp);
		memset(used, 0, sizeof(used));
		for(i=n, ans=0, on=0; i>0; i--, ans+=dsp)
		{
			for(j=0; j<m; j++)
			{
				/*printf("%d %d\n", ans/wsp, f[j]);*/
				if(used[j] == 0 && (ans+dsp)/wsp >= f[j])
				{
					/*printf("XD\n");*/
					used[j] = 1;
				}
			}
			for(j=0, open=0; j<m; j++)
			{
				if(used[j] == 0 && f[j] > i-1)
				{
					if(f[j]-i+1 > (ans+dsp)/wsp && f[j]*wsp > ans+dsp*i+csp)
					{
						open = 1;
						break;
					}
				}
				else if(f[j] <= i-1)
				{
					break;
				}
			}
			if(open)
			{
				/*printf("open\n");*/
				on = 1;
				for(j=0; j<m; j++)
				{
					if(used[j] == 0 && ab(f[j]-i) <= ans/wsp)
					{
						used[j] = 1;
					}
				}
				ans += csp;
			}
		}
		if(on == 0)
		{
			ans = f[0]*wsp;
		}
		printf("%d\n", ans);
	}
	return 0;
}

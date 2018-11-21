#include <stdio.h>
#include <stdlib.h>

int p[16384], q[16384], r[16384];
char nam[16384][32];

int comp(const void *pp, const void *qq)
{
	return p[*(int*)pp] - p[*(int*)qq];
}

int main()
{
	int count, n, m, i, t, res, ll, mm, rr;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%s%d%d", nam[i], &p[i], &q[i]);
			r[i] = i;
		}
		qsort(r, n, sizeof(r[0]), comp);
		scanf("%d", &m);
		while (m--)
		{
			scanf("%d", &t);
			res = -1;
			ll = 0;
			rr = n-1;
			i = 0;
			while (ll <= rr)
			{
				mm = ((ll+rr) >> 1);
				if (t >= p[r[mm]])
				{
					rr = mm-1;
					i = mm;
					if (q[r[mm]] >= t)
					{
						if (res >= 0)
						{
							res = -2;
							break;
						}
						res = r[mm];
					}
				}
				else
				{
					ll = mm+1;
				}
			}
			if (res != -2)
			{
				res = -1;
				for (; i<n; i++)
				{
					if (p[r[i]] <= t && q[r[i]] >= t)
					{
						if (res >= 0)
						{
							res = -2;
							break;
						}
						else
						{
							res = r[i];
						}
					}
					else if (p[r[i]] > t)
					{
						break;
					}
				}
			}
			if (res < 0)
			{
				puts("UNDETERMINED");
			}
			else
			{
				puts(nam[res]);
			}
		}
		if (count)
		{
			puts("");
		}
	}
	return 0;
}

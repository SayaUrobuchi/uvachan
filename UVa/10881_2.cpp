#include <stdio.h>
#include <algorithm>

const int N = 10005;

int ant[N], res[N], dir[N];
int idx[N], ridx[N];
char ans[N][32];
char buf[16];

bool comp(int p, int q)
{
	return ant[p] < ant[q];
}

bool tcomp(int p, int q)
{
	return res[idx[p]] < res[idx[q]];
}

int main()
{
	int count, cas, n, len, tim, i, j, k, p, q, t;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &len, &tim, &n);
		for (i=0; i<n; i++)
		{
			scanf("%d%s", &t, buf);
			ant[i] = t;
			dir[i] = *buf;
			if (*buf == 'R')
			{
				res[i] = t + tim;
			}
			else
			{
				res[i] = t - tim;
			}
			idx[i] = i;
			ridx[i] = i;
		}
		std::sort(idx, idx+n, comp);
		std::sort(ridx, ridx+n, tcomp);
		for (i=0; i<n; i++)
		{
			j = idx[ridx[i]];
			if (res[j] < 0 || res[j] > len)
			{
				sprintf(ans[idx[i]], "Fell off");
			}
			else
			{
				sprintf(ans[idx[i]], "%d %s", res[j], (i>0&&res[idx[ridx[i-1]]]==res[j])||(i+1<n&&res[idx[ridx[i+1]]]==res[j]) ? "Turning" : (dir[j] == 'R' ? "R" : "L"));
			}
		}
		printf("Case #%d:\n", ++cas);
		for (i=0; i<n; i++)
		{
			puts(ans[i]);
		}
		puts("");
	}
	return 0;
}

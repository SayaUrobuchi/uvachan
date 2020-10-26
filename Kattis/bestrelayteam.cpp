#include <iostream>
#include <algorithm>

const int N = 1024;

int idx[N];
double a[N], b[N];
char nam[N][32];

bool comp(int p, int q)
{
	return b[p] < b[q];
}

int main()
{
	int n, i, j, k;
	long long st, ans;
	double t, best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%s%lf%lf", nam[i], &a[i], &b[i]);
			idx[i] = i;
		}
		std::sort(idx, idx+n, comp);
		for (i=0, best=1e100; i<n; i++)
		{
			t = a[i];
			st = 0;
			for (j=0, k=0; k<3; j++)
			{
				if (idx[j] != i)
				{
					++k;
					t += b[idx[j]];
					st = st*1000 + idx[j];
				}
			}
			if (t < best)
			{
				best = t;
				ans = st * 1000 + i;
			}
		}
		printf("%.2lf\n", best);
		for (i=0; i<4; i++, ans/=1000)
		{
			puts(nam[ans%1000]);
		}
	}
	return 0;
}

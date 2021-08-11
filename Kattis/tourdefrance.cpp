#include <iostream>
#include <algorithm>
using namespace std;
using frac = pair<int, int>;

int ary[1024];
frac bry[1048576];

bool comp(frac a, frac b)
{
	return a.first*b.second < b.first*a.second;
}

int main()
{
	int n, m, i, j, k, t;
	double rat, best;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for (i=0, k=0; i<m; i++)
		{
			scanf("%d", &t);
			for (j=0; j<n; j++)
			{
				bry[k++] = {t, ary[j]};
			}
		}
		sort(bry, bry+k, comp);
		for (i=1; i<k; i++)
		{
			rat = bry[i].first * bry[i-1].second / (double)bry[i].second / (double)bry[i-1].first;
			if (i == 1 || rat > best)
			{
				best = rat;
			}
		}
		printf("%.2lf\n", best);
	}
	return 0;
}

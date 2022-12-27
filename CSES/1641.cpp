#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> ary[5005];

int main()
{
	int n, m, i, j, k, t, a, b, c;
	bool found;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i].first);
			ary[i].second = i;
		}
		sort(ary, ary+n);
		for (i=0, found=false; i+2<n&&!found; i++)
		{
			for (j=i+1, k=n-1, t=m-ary[i].first; j<k; j++)
			{
				for (; k>j&&ary[j].first+ary[k].first>t; k--);
				if (k > j && ary[j].first+ary[k].first == t)
				{
					found = true;
					a = ary[i].second;
					b = ary[j].second;
					c = ary[k].second;
				}
			}
		}
		if (found)
		{
			printf("%d %d %d\n", a+1, b+1, c+1);
		}
		else
		{
			puts("IMPOSSIBLE");
		}
	}
	return 0;
}


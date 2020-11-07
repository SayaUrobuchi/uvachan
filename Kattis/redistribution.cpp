#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> ary[1024];

int main()
{
	int n, i, sum;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, sum=0; i<n; i++)
		{
			scanf("%d", &ary[i].first);
			ary[i].second = i+1;
			sum += ary[i].first;
		}
		sort(ary, ary+n, greater<pair<int, int> >());
		if ((ary[0].first<<1) > sum)
		{
			puts("impossible");
		}
		else
		{
			printf("%d", ary[0].second);
			for (i=1; i<n; i++)
			{
				printf(" %d", ary[i].second);
			}
			puts("");
		}
	}
	return 0;
}

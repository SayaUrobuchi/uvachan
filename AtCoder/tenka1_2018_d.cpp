#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, i, j, k, l, r;
	scanf("%d", &n);
	int ans = -100;
	for (l=1, r=2005; l<=r; )
	{
		int mid = ((l+r) >> 1);
		int t = mid * (mid+1) / 2;
		if (t <= n)
		{
			ans = mid;
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	if (ans * (ans+1) / 2 == n)
	{
		puts("Yes");
		++ans;
		vector< vector<int> > v(ans);
		for (i=0, k=1; i<ans; i++)
		{
			for (j=i+1; j<ans; j++, k++)
			{
				v[i].emplace_back(k);
				v[j].emplace_back(k);
			}
		}
		printf("%d\n", ans);
		for (i=0; i<ans; i++)
		{
			printf("%llu", v[i].size());
			for (j=0; j<v[i].size(); j++)
			{
				printf(" %d", v[i][j]);
			}
			puts("");
		}
	}
	else
	{
		puts("No");
	}
	return 0;
}
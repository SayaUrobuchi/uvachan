#include <iostream>
#include <algorithm>
using namespace std;

pair<int, int> pp[128];

int main()
{
	int n, i, j, t, ans;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &pp[i].first, &pp[i].second);
		}
		sort(pp, pp+n);
		for (i=0, ans=0; i<n; i=j, ans++)
		{
			for (j=i+1, t=pp[i].second; j<n&&pp[j].first<=t; j++)
			{
				t = min(t, pp[j].second);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

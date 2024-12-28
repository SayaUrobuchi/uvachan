#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	int ans = 2e9;
	bool found = false;
	for (i=0; i<n; i++)
	{
		int cost, tim;
		scanf("%d%d", &cost, &tim);
		if (tim <= m)
		{
			found = true;
			ans = min(ans, cost);
		}
	}
	if (!found)
	{
		puts("TLE");
	}
	else
	{
		printf("%d\n", ans);
	}
	return 0;
}

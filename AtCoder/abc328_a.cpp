#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	int ans = 0;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t <= m)
		{
			ans += t;
		}
	}
	printf("%d\n", ans);
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int count, cas;
	scanf("%d", &count);
	for (cas=1; cas<=count; ++cas)
	{
		int n, i;
		scanf("%d", &n);
		int ans = 0;
		for (i=0; i<n; i++)
		{
			int t;
			scanf("%d", &t);
			ans += (t & 1);
		}
		printf("%d\n", ans);
	}
	return 0;
}

#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	int best = 0;
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
		best = max(best, ary[i]);
	}
	int ans = 0;
	for (i=0; i<n; i++)
	{
		if (ary[i] < best)
		{
			ans = max(ans, ary[i]);
		}
	}
	printf("%d\n", ans);
	return 0;
}

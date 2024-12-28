#include <iostream>
using namespace std;

const int N = 128;

int ary[N];

int main()
{
	int n, m, i, j;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	int ans = 0;
	for (j=0; j<m; j++)
	{
		int t;
		scanf("%d", &t);
		for (i=0; i<n; i++)
		{
			ans += (ary[i] <= t);
		}
	}
	printf("%d\n", ans);
	return 0;
}

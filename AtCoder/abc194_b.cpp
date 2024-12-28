#include <iostream>
using namespace std;

const int N = 1024;

int ary[N], bry[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int ans = 2e9;
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i], &bry[i]);
		ans = min(ans, ary[i] + bry[i]);
		for (j=0; j<i; j++)
		{
			ans = min(ans, min(max(ary[i], bry[j]), max(bry[i], ary[j])));
		}
	}
	printf("%d\n", ans);
	return 0;
}

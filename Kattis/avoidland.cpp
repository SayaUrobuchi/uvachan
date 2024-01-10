#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1000005;

int ary[N], bry[N];

int solve(int ary[], int n)
{
	int i;
	int ret = 0;
	sort(ary, ary+n);
	for (i=0; i<n; i++)
	{
		ret += abs(ary[i] - (i+1));
	}
	return ret;
}

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i], &bry[i]);
	}
	int ans = solve(ary, n) + solve(bry, n);
	printf("%d\n", ans);
	return 0;
}

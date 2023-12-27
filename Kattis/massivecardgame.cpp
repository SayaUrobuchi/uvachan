#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, m, i, a, b;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		int st = distance(ary, lower_bound(ary, ary+n, a));
		int ed = distance(ary, upper_bound(ary, ary+n, b));
		printf("%d\n", ed-st);
	}
	return 0;
}

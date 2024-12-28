#include <iostream>
#include <algorithm>
using namespace std;

const int N = 100005;

int ary[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+n);
	int best = 0;
	int second = 0;
	for (i=1; i<n; i++)
	{
		if (ary[i] == ary[i-1])
		{
			second = best;
			best = ary[i];
			++i;
		}
	}
	printf("%lld\n", best*1LL*second);
	return 0;
}

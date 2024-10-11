#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 100005;

pp ary[N];

int main()
{
	int n, i;
	long long m;
	scanf("%d%lld", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &ary[i].first, &ary[i].second);
	}
	sort(ary, ary+n);
	long long sum = 0;
	for (i=0; i<n&&sum<m; sum+=ary[i].second, i++);
	printf("%d\n", ary[i-1].first);
	return 0;
}

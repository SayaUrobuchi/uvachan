#include <iostream>
#include <algorithm>
using namespace std;

const int N = (131072 << 1);
const int M = 1000000007;

pair<int, int> ary[N];

int main()
{
	int n, n2, i, t, ans, cur, typ;
	scanf("%d", &n);
	n2 = (n << 1);
	for (i=0; i<n2; i++)
	{
		scanf("%d", &ary[i].first);
		ary[i].second = i;
	}
	sort(ary, ary+n2);
	for (i=0, cur=0, typ=0, ans=1; i<n2; i++)
	{
		t = ary[i].second / n;
		if (cur == 0)
		{
			typ = t;
		}
		if (typ == t)
		{
			++cur;
		}
		else
		{
			ans = ((long long)ans * cur) % M;
			--cur;
		}
	}
	printf("%d\n", ans);
	return 0;
}
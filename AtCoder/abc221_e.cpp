#include <iostream>
#include <algorithm>
using namespace std;

const int MOD = 998244353;

int ans;
int tbl[400005];
pair<int, int> ary[400005], temp[400005];

void recurs(int l, int r)
{
	if (l == r)
	{
		return;
	}
	int m = ((l+r) >> 1);
	recurs(l, m);
	recurs(m+1, r);
	for (int i=l, j=m+1, k=l, t=0; k<=r; k++)
	{
		if (j > r || (i <= m && ary[i].first <= ary[j].first))
		{
			temp[k] = ary[i];
			++i;
			t = (t + tbl[m-temp[k].second]) % MOD;
		}
		else
		{
			temp[k] = ary[j];
			++j;
			ans = (ans + (long long)t * tbl[temp[k].second-m-1]) % MOD;
		}
	}
	copy(temp+l, temp+r+1, ary+l);
}

int main()
{
	int n, i;
	scanf("%d", &n);
	tbl[0] = 1;
	for (i=1; i<=n; i++)
	{
		tbl[i] = (tbl[i-1] << 1) % MOD;
	}
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i].first);
		ary[i].second = i;
	}
	ans = 0;
	recurs(0, n-1);
	printf("%d\n", ans);
	return 0;
}
#include <iostream>
using namespace std;

const int N = 100005;

int ary[N];
long long pre[N], post[N];

int main()
{
	int n, i, ans;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
	}
	pre[0] = -1e10;
	for (i=1; i<=n; i++)
	{
		pre[i] = max(pre[i-1], (long long)ary[i]);
	}
	post[n+1] = 1e10;
	for (i=n; i>=1; i--)
	{
		post[i] = min(post[i+1], (long long)ary[i]);
	}
	for (i=1, ans=0; i<=n; i++)
	{
		if (ary[i] >= pre[i-1] && ary[i] < post[i+1])
		{
			++ans;
		}
	}
	printf("%d\n", ans);
	return 0;
}
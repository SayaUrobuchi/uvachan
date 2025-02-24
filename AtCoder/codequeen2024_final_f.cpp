#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using pp = pair<long long, int>;
using pq_t = priority_queue<pp, vector<pp>, greater<pp> >;

const int N = 500005;

int ary[N];
long long pre[N<<1];

int main()
{
	int n, i;
	scanf("%d", &n);
	long long sum = 0;
	for (i=1; i<=n; i++)
	{
		scanf("%d", &ary[i]);
		pre[i] = pre[i-1] + ary[i];
		sum += ary[i];
	}
	for (i=n+1; i<=(n<<1); i++)
	{
		pre[i] = pre[i-1] + ary[i-n];
	}
	pq_t pq;
	for (i=1; i<n; i++)
	{
		pq.emplace((pre[i]-pre[0])*n - sum*(i-0), i);
	}
	long long fix = 0;
	int ans = -1;
	for (i=1; i<=n; i++)
	{
		while (pq.top().second < i)
		{
			pq.pop();
		}
		if (pq.top().first + fix >= 0)
		{
			ans = i;
			break;
		}
		fix -= ary[i] * 1LL * n;
		fix += sum;
		long long nxt = (pre[i+n-1] - pre[i]) * n - sum * (n-1);
		pq.emplace(nxt-fix, i+n-1);
	}
	printf("%d\n", ans);
	return 0;
}

#include <iostream>
using namespace std;

const int M = 100000;
const int N = M + 5;

int ucnt;
int ary[N], used[N], pos[N];

int main()
{
	int n, i, j, t, u, ans;
	long long m;
	while (scanf("%d%lld", &n, &m) == 2)
	{
		++ucnt;
		pos[n] = 0;
		used[n] = ucnt;
		ary[0] = n;
		for (i=1, t=n; i<=m; i++, t=u)
		{
			for (j=t, u=t; j; u+=j%10, j/=10);
			u %= M;
			if (used[u] == ucnt)
			{
				ans = (m-pos[u]) % (i-pos[u]) + pos[u];
				break;
			}
			else
			{
				ans = i;
				pos[u] = i;
				used[u] = ucnt;
				ary[i] = u;
			}
		}
		printf("%d\n", ary[ans]);
	}
	return 0;
}

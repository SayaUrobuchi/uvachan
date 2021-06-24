#include <iostream>
#include <vector>
using namespace std;

long long ans;
int ucnt, used[16384], num[16384], need[16384];
vector<int> v[16384];

void recurs(int cur)
{
	int nxt, i;
	if (used[cur] == ucnt)
	{
		return;
	}
	used[cur] = ucnt;
	need[cur] = num[cur]-1;
	for (i=0; i<v[cur].size(); i++)
	{
		nxt = v[cur][i];
		recurs(nxt);
		need[cur] += need[nxt];
		ans += abs(need[nxt]);
	}
}

int main()
{
	int n, m, i, j;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		for (i=1; i<=n; i++)
		{
			scanf("%*d%d%d", &num[i], &m);
			v[i].resize(m);
			for (j=0; j<m; j++)
			{
				scanf("%d", &v[i][j]);
			}
		}
		++ucnt;
		ans = 0;
		for (i=1; i<=n; i++)
		{
			recurs(i);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

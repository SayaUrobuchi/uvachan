#include <iostream>
#include <map>
using namespace std;
using mm = map<long long, int>;

int ucnt, used[512][16384];
long long dp[512][16384];

int main()
{
	int n, m, i, j, p, q, a, b, c;
	mm mp;
	mm::iterator it;
	while (scanf("%d%d", &m, &n) == 2)
	{
		++ucnt;
		used[0][0] = ucnt;
		for (i=1; i<=n; i++)
		{
			scanf("%d%d%d", &a, &b, &c);
			mp.clear();
			for (j=0, q=-a, p=-b; j<=m; j++, q++, p++)
			{
				if (q >= 0 && used[i-1][q] == ucnt)
				{
					++mp[dp[i-1][q]];
				}
				dp[i][j] = -1;
				if (used[i-1][j] == ucnt)
				{
					dp[i][j] = dp[i-1][j];
					used[i][j] = ucnt;
				}
				if (mp.size())
				{
					it = mp.end();
					--it;
					dp[i][j] = max(dp[i][j], it->first + c);
					used[i][j] = ucnt;
				}
				if (p >= 0 && used[i-1][p] == ucnt)
				{
					it = mp.find(dp[i-1][p]);
					--(it->second);
					if (!(it->second))
					{
						mp.erase(it);
					}
				}
			}
		}
		printf("%lld\n", dp[n][m]);
	}
	return 0;
}

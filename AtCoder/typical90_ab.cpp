#include <iostream>
#include <vector>
using namespace std;

const int N = 1000;

int delta[N+5], cnt[131072];
vector<int> st[N+5][N+5], ed[N+5][N+5];

int main()
{
	int n, i, j, k, t, a, b, c, d;
	while (scanf("%d", &n) == 1)
	{
		for (i=0; i<=N; i++)
		{
			delta[i] = 0;
			for (j=0; j<=N; j++)
			{
				st[i][j].clear();
				ed[i][j].clear();
			}
		}
		for (i=1; i<=n; i++)
		{
			cnt[i] = 0;
			scanf("%d%d%d%d", &a, &b, &c, &d);
			--c;
			st[a][b].emplace_back(d);
			ed[c][d].emplace_back(b);
		}
		for (i=0; i<=N; i++)
		{
			for (j=0, t=0; j<=N; j++)
			{
				for (k=0; k<st[i][j].size(); k++)
				{
					--delta[st[i][j][k]];
				}
				delta[j] += st[i][j].size();
				t += delta[j];
				++cnt[t];
				for (k=0; k<ed[i][j].size(); k++)
				{
					--delta[ed[i][j][k]];
				}
				delta[j] += ed[i][j].size();
			}
		}
		for (i=1; i<=n; i++)
		{
			printf("%d\n", cnt[i]);
		}
	}
	return 0;
}

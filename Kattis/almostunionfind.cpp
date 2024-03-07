#include <iostream>
using namespace std;

const int N = 100005;
const int N2 = (N << 1);

int par[N2], id[N], cnt[N];
long long sum[N];

int getpar(int cur)
{
	if (par[cur] < 0)
	{
		return cur;
	}
	return par[cur] = getpar(par[cur]);
}

int main()
{
	int n, m, i, nxt_id;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			id[i] = i;
			par[i] = -1;
			sum[i] = i;
			cnt[i] = 1;
		}
		nxt_id = n + 1;
		for (i=0; i<m; i++)
		{
			int cmd, a, b;
			scanf("%d", &cmd);
			if (cmd == 1)
			{
				scanf("%d%d", &a, &b);
				a = getpar(id[a]);
				b = getpar(id[b]);
				if (a != b)
				{
					par[a] = b;
					sum[b] += sum[a];
					cnt[b] += cnt[a];
				}
			}
			else if (cmd == 2)
			{
				scanf("%d%d", &a, &b);
				int r = getpar(id[a]);
				b = getpar(id[b]);
				if (r != b)
				{
					id[a] = nxt_id;
					++nxt_id;
					par[id[a]] = b;
					sum[b] += a;
					++cnt[b];
					sum[r] -= a;
					--cnt[r];
				}
			}
			else
			{
				scanf("%d", &a);
				a = getpar(id[a]);
				printf("%d %lld\n", cnt[a], sum[a]);
			}
		}
	}
	return 0;
}

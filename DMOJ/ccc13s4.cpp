#include <iostream>
#include <vector>
using namespace std;

const int N = 1048576;

int ucnt, used[N];
int qq[N];
vector<int> v[N];

int main()
{
	int n, m, i, j, k, cur, nxt, p, q;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=1; i<=n; i++)
		{
			v[i].clear();
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			v[p].emplace_back(q);
		}
		scanf("%d%d", &p, &q);
		qq[0] = p;
		ucnt++;
		used[p] = ucnt;
		for (i=0, j=1; i<j; i++)
		{
			cur = qq[i];
			if (cur == q)
			{
				break;
			}
			for (k=0; k<v[cur].size(); k++)
			{
				nxt = v[cur][k];
				if (used[nxt] != ucnt)
				{
					used[nxt] = ucnt;
					qq[j] = nxt;
					j++;
				}
			}
		}
		if (i < j)
		{
			puts("yes");
			continue;
		}
		qq[0] = q;
		ucnt++;
		used[q] = ucnt;
		for (i=0, j=1; i<j; i++)
		{
			cur = qq[i];
			if (cur == p)
			{
				break;
			}
			for (k=0; k<v[cur].size(); k++)
			{
				nxt = v[cur][k];
				if (used[nxt] != ucnt)
				{
					used[nxt] = ucnt;
					qq[j] = nxt;
					j++;
				}
			}
		}
		if (i < j)
		{
			puts("no");
			continue;
		}
		puts("unknown");
	}
	return 0;
}

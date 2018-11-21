#include <stdio.h>
#include <vector>

#define M 1000005
#define N 100005

int h[N], used[N];
int qq[M], qs[M];
std::vector<int> v[N];

int main()
{
	int n, m, o, p, q, i, j, k, t, ed, cnt, count, ans;
	cnt = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		ed = 0;
		for (i=0; i<n; i++)
		{
			scanf("%d", &h[i]);
			if (h[i] < h[ed])
			{
				ed = i;
			}
			v[i].clear();
		}
		for (i=0; i<m; i++)
		{
			scanf("%d%d", &p, &q);
			v[p].push_back(q);
			v[q].push_back(p);
		}
		qq[0] = o;
		qs[0] = 0;
		++cnt;
		used[o] = cnt;
		for (i=0, j=1; i<j; i++)
		{
			p = qq[i];
			if (h[p] == h[ed])
			{
				t = qs[i];
				break;
			}
			for (k=0; k<v[p].size(); k++)
			{
				q = v[p][k];
				if (used[q] != cnt)
				{
					used[q] = cnt;
					qq[j] = q;
					qs[j] = qs[i] + 6;
					++j;
				}
			}
		}
		if (i >= j)
		{
			printf("Case #%d: Call 119!\n", cnt);
		}
		else
		{
			ans = 0;
			for (i=o, j=0; i!=ed; j++)
			{
				p = -1;
				for (k=0; k<v[i].size(); k++)
				{
					q = v[i][k];
					if (h[q] < h[i] && (p < 0 || h[q] < h[p]))
					{
						p = q;
					}
				}
				if (p < 0)
				{
					break;
				}
				i = p;
				if (h[i] == h[ed])
				{
					ans = j+1;
					break;
				}
			}
			printf("Case #%d: %d\n", cnt, t>ans?t-ans:ans-t);
		}
	}
	return 0;
}

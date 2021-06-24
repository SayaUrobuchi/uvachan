#include <iostream>
#include <algorithm>
using namespace std;

using pp = pair<int, int>;
using pppp = pair<pp, pp>;

const int MF = 128;
const int MK = 1024;
const int MS = 131072;

int cnt[MF], ptr[MF], dis[MF][MK];
long long res[MF];
pp pos[MF][MK];
pppp stu[MS];

int main()
{
	int n, m, p, q, r, i, j, f, x, y, t;
	long long ans;
	while (scanf("%d%d%d%d%d", &n, &m, &p, &q, &r) == 5)
	{
		for (i=0; i<p; i++)
		{
			scanf("%d", &cnt[i]);
			for (j=0; j<cnt[i]; j++)
			{
				scanf("%d%d", &pos[i][j].first, &pos[i][j].second);
			}
			sort(pos[i], pos[i]+cnt[i]);
			ptr[i] = 0;
		}
		for (i=0; i<q; i++)
		{
			scanf("%d%d%d%d", &stu[i].second.first, &stu[i].second.second, 
				&stu[i].first.first, &stu[i].first.second);
		}
		sort(stu, stu+q);
		for (i=0; i<q; i++)
		{
			f = stu[i].first.second - 1;
			x = stu[i].second.first;
			y = stu[i].second.second;
			t = ptr[f];
			dis[f][t] = abs(x-pos[f][t].first) + abs(y-pos[f][t].second);
			++ptr[f];
		}
		for (i=0; i<p; i++)
		{
			scanf("%d", &t);
			if (ptr[i] >= t)
			{
				res[i] = 0;
				sort(dis[i], dis[i]+ptr[i]);
				for (j=0; j<t; j++)
				{
					res[i] += dis[i][j];
				}
			}
			else
			{
				res[i] = 1e18;
			}
		}
		sort(res, res+p);
		for (i=0, ans=0; i<r; i++)
		{
			ans += res[i];
		}
		printf("%lld\n", ans);
	}
	return 0;
}

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 200005;

int ary[N];

int main()
{
	int count;
	scanf("%d", &count);
	while (count--)
	{
		int n, m, i;
		scanf("%d%d", &n, &m);
		int up = 0;
		int down = 0;
		long long ans = 0;
		vector<int> toup, toeven, todown;
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
			ary[i] %= m;
			int half = (m+1) / 2;
			if (ary[i] <= m-ary[i])
			{
				++down;
				toup.emplace_back(half-ary[i]);
				todown.emplace_back(half-ary[i]+(m-half));
				ans += ary[i];
			}
			else
			{
				++up;
				todown.emplace_back(m-ary[i]);
				toup.emplace_back(m-ary[i]+half);
				ans += m-ary[i];
			}
		}
		sort(toup.begin(), toup.end());
		sort(todown.begin(), todown.end());
		toup.emplace_back(m-1);
		todown.emplace_back(m-1);
		toup.emplace_back(2e9);
		todown.emplace_back(2e9);
		int cur = 0;
		long long total = ans;
		int upp = 0;
		int downp = 0;
		while (cur < m)
		{
			int nxt = min(toup[upp], todown[downp]);
			if (nxt >= m)
			{
				break;
			}
			int d = max(0, nxt - cur);
			total += (down - up) * 1LL * d;
			while (upp < toup.size() && toup[upp] == nxt)
			{
				++upp;
				--down;
				++up;
				if (m % 2)
				{
					--total;
				}
			}
			while (downp < todown.size() && todown[downp] == nxt)
			{
				++downp;
				++down;
				--up;
			}
			ans = min(ans, total);
			cur = nxt;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

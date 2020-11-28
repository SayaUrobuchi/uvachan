#include <iostream>
#include <cstring>
#include <cmath>

const int WS = 10;
const double EPS = 1e-8;
const double AS = 9.0/16.0;

int cnt[1024], len[1024];
char s[1048576];

int main()
{
	int cas, n, m, i, mc, mh, tw, ans, h, w;
	cas = 0;
	while (scanf("%d%d", &m, &n) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0, mc=0; i<n; i++)
		{
			scanf("%s%d", s, &cnt[i]);
			len[i] = strlen(s);
			if (cnt[i] > mc)
			{
				mc = cnt[i];
			}
		}
		for (i=0, tw=m, mh=0, ans=0; i<n; i++)
		{
			h = 8 + (int)(ceil(40.0 * (cnt[i]-4.0) / (mc-4.0))+EPS);
			w = (int)(ceil(AS * len[i] * h)+EPS);
			if (tw + WS + w <= m)
			{
				tw += WS + w;
				mh = std::max(mh, h);
			}
			else
			{
				ans += mh;
				tw = w;
				mh = h;
			}
		}
		printf("CLOUD %d: %d\n", ++cas, ans+mh);
	}
	return 0;
}

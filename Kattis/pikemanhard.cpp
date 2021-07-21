#include <iostream>
#include <cstring>
using namespace std;

const int M = 1000000007;

int ary[1048576], tbl[1048576], cnt[1048576];

int main()
{
	int n, a, b, c, t, i, solved, penalty, st, len, loop, remain;
	long long m, u, tim;
	while (scanf("%d%lld", &n, &m) == 2)
	{
		scanf("%d%d%d%d", &a, &b, &c, &t);
		ary[0] = t;
		memset(tbl, -1, sizeof(tbl[0])*(c+5));
		tbl[t] = 0;
		solved = -1;
		st = n;
		len = 0;
		for (i=1; i<n; i++)
		{
			ary[i] = ((long long)ary[i-1]*a + b) % c + 1;
			if (tbl[ary[i]] != -1)
			{
				st = tbl[ary[i]];
				len = i - st;
				break;
			}
			tbl[ary[i]] = i;
		}
		memset(cnt, 0, sizeof(cnt[0])*(c+5));
		for (i=0; i<st; i++)
		{
			++cnt[ary[i]];
		}
		if (len)
		{
			loop = (n-st) / len;
			remain = (n-st) % len;
			for (i=0; i<len; i++)
			{
				cnt[ary[st+i]] += loop;
				if (i < remain)
				{
					++cnt[ary[st+i]];
				}
			}
		}
		for (i=1, solved=0, penalty=0, tim=0; i<=c&&i<=m; i++)
		{
			u = cnt[i];
			if (m < (long long)i * cnt[i])
			{
				u = m / i;
			}
			m -= u * i;
			solved += u;
			long long p = (tim+i+(tim+(long long)u*i));
			if (u & 1)
			{
				p = (p/2)%M * u;
			}
			else
			{
				p = p%M * u/2;
			}
			penalty = (penalty + p) % M;
			tim += u * i;
		}
		printf("%d %d\n", solved, penalty);
	}
	return 0;
}

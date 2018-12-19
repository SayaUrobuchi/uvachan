#include <stdio.h>

const int BIT = 1048576;
const int N = 24;

int pos[N], w[N];
int used[BIT], from[BIT];
int qq[BIT], ql[BIT], qr[BIT];

void trace(int stat)
{
	int idx = from[stat];
	//printf("==== %d %d\n", stat, idx);
	if (idx >= 0)
	{
		trace(stat + (1 << idx));
		printf("%d %d\n", pos[idx]>>1, w[idx]);
	}
}

int main()
{
	int len, wei, n, left, right, cur, nxt, nl, nr, i, j, k;
	int cas, cnt;
	cnt = 0;
	cas = 0;
	while (scanf("%d%d%d", &len, &wei, &n) == 3)
	{
		if (len == 0 && wei == 0 && n == 0)
		{
			break;
		}
		left = 3 * wei;
		right = -3 * wei;
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &pos[i], &w[i]);
			pos[i] <<= 1;
			left += (pos[i] + 3) * w[i];
			right += (pos[i] - 3) * w[i];
		}
		printf("Case %d:\n", ++cas);
		if (left < 0 || right > 0)
		{
			puts("Impossible");
			continue;
		}
		++cnt;
		qq[0] = (1 << n) - 1;
		ql[0] = left;
		qr[0] = right;
		from[qq[0]] = -1;
		used[qq[0]] = cnt;
		for (i=0, j=1; i<j; i++)
		{
			cur = qq[i];
			left = ql[i];
			right = qr[i];
			for (k=0; k<n; k++)
			{
				if (cur & (1 << k))
				{
					nxt = cur - (1 << k);
					if (used[nxt] != cnt)
					{
						nl = left - (pos[k] + 3) * w[k];
						nr = right - (pos[k] - 3) * w[k];
						if (nl >= 0 && nr <= 0)
						{
							used[nxt] = cnt;
							from[nxt] = k;
							qq[j] = nxt;
							ql[j] = nl;
							qr[j] = nr;
							j++;
						}
					}
				}
			}
		}
		if (used[0] == cnt)
		{
			trace(0);
		}
		else
		{
			puts("Impossible");
		}
	}
	return 0;
}

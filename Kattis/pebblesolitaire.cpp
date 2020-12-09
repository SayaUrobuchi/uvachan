#include <iostream>

const int ALL = (1<<12)-1;

int ucnt;
int qq[(1<<13)], used[(1<<13)];
char s[1024];

int main()
{
	int count, i, j, k, st, nxt, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", s);
		for (i=0, st=0; s[i]; i++)
		{
			st = (st<<1) + (s[i] == 'o' ? 1 : 0);
		}
		qq[0] = st;
		used[st] = ++ucnt;
		for (i=0, j=1; i<j; i++)
		{
			for (k=0; k<12; k++)
			{
				if (qq[i] & (1 << k))
				{
					nxt = qq[i];
					if (k >= 2 && (nxt & (1<<(k-1))) && !(nxt & (1<<(k-2))))
					{
						nxt |= 1 << (k-2);
						nxt &= ALL - (1<<(k-1)) - (1<<k);
					}
					if (used[nxt] != ucnt)
					{
						used[nxt] = ucnt;
						qq[j] = nxt;
						++j;
					}
					nxt = qq[i];
					if (k+2 < 12 && (nxt & (1<<(k+1))) && !(nxt & (1<<(k+2))))
					{
						nxt |= 1 << (k+2);
						nxt &= ALL - (1<<(k+1)) - (1<<k);
					}
					if (used[nxt] != ucnt)
					{
						used[nxt] = ucnt;
						qq[j] = nxt;
						++j;
					}
				}
			}
		}
		nxt = qq[j-1];
		for (i=0, ans=0; i<12; i++)
		{
			if (nxt & (1<<i))
			{
				++ans;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

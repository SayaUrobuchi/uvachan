#include <stdio.h>
#include <string.h>

int cnt[128];
char buf[10000000], sbuf0[10000000], sbuf1[10000000];

int main()
{
	int n, i, t, len;
	char *resp, *sp, *sq, *st;
	while (scanf("%d", &n) == 1)
	{
		if (!n)
		{
			break;
		}
		for (i=0; i<n; i++)
		{
			scanf("%d", &t);
			cnt[t]++;
		}
		resp = buf;
		sp = sbuf0;
		sq = sbuf1;
		for (i=1; i<=100; i++)
		{
			if (cnt[i])
			{
				sprintf(sp, " %d", i);
				len = strlen(sp);
				while (cnt[i])
				{
					if (cnt[i] & 1)
					{
						strcpy(resp, sp);
						resp += len;
					}
					strcpy(sq, sp);
					strcpy(sq+len, sp);
					st = sp;
					sp = sq;
					sq = st;
					len <<= 1;
					cnt[i] >>= 1;
				}
			}
		}
		puts(buf+1);
	}
	return 0;
}

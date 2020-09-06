#include <stdio.h>
#include <string.h>

int cnt[4], tbl[128], used[64];
char buf[1024];

int main()
{
	int i, suit, num, id, gg;
	char c;
	tbl['P'] = 0;
	tbl['K'] = 1;
	tbl['H'] = 2;
	tbl['T'] = 3;
	while (scanf("%s", buf) == 1)
	{
		memset(cnt, 0, sizeof(cnt));
		memset(used, 0, sizeof(used));
		for (i=0, gg=0; buf[i]; i+=3)
		{
			sscanf(buf+i, "%c%d", &c, &num);
			suit = tbl[c];
			id = suit*13 + num-1;
			if (!used[id])
			{
				used[id] = 1;
				cnt[suit]--;
			}
			else
			{
				gg = 1;
			}
		}
		if (gg)
		{
			puts("GRESKA");
		}
		else
		{
			printf("%d %d %d %d\n", 13+cnt[0], 13+cnt[1], 13+cnt[2], 13+cnt[3]);
		}
	}
	return 0;
}

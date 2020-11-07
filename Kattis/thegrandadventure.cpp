#include <iostream>

int stk[1048576], sn;
int tbl[128];
char buf[1048576];

int main()
{
	int count, i, sn;
	tbl['$'] = 1;
	tbl['*'] = 2;
	tbl['|'] = 3;
	tbl['b'] = -1;
	tbl['j'] = -2;
	tbl['t'] = -3;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%s", buf);
		for (i=0, sn=-1; buf[i]; i++)
		{
			if (tbl[buf[i]] > 0)
			{
				stk[++sn] = tbl[buf[i]];
			}
			else if (tbl[buf[i]] < 0)
			{
				for (; sn>=0&&stk[sn]+tbl[buf[i]]!=0; sn--);
				if (sn < 0)
				{
					break;
				}
				sn--;
			}
		}
		if (buf[i] || sn >= 0)
		{
			puts("NO");
		}
		else
		{
			puts("YES");
		}
	}
	return 0;
}

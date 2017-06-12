#include <stdio.h>

#define M 1000

int tbl[128];
char s[1048576];

int main()
{
	int count, i, last, cnt, res;
	tbl['C'] = 12010;
	tbl['H'] = 1008;
	tbl['O'] = 16000;
	tbl['N'] = 14010;
	gets(s);
	sscanf(s, "%d", &count);
	while (count--)
	{
		gets(s);
		last = 0;
		cnt = 0;
		res = 0;
		for (i=0; s[i]; i++)
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				cnt = cnt * 10 + (s[i]-'0');
			}
			else
			{
				if (last)
				{
					if (!cnt)
					{
						cnt = 1;
					}
					res += tbl[last] * cnt;
				}
				last = s[i];
				cnt = 0;
			}
		}
		if (last)
		{
			if (!cnt)
			{
				cnt = 1;
			}
			res += tbl[last] * cnt;
		}
		printf("%d.%03d\n", res/M, res%M);
	}
	return 0;
}

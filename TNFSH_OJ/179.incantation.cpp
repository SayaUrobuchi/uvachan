#include <stdio.h>

const int M = 27;

char s[10005];

int main()
{
	int i, j, st, ed, cur, md, flag, ans, last, cnt;
	char *p;
	while (gets(s))
	{
		st = 0;
		for (i=0, p=s; i<3; i++)
		{
			st = st*M + (p[i]-'A'+1);
		}
		ed = 0;
		for (i=0, p=s+3; i<3; i++)
		{
			ed = ed*M + (p[i]-'A'+1);
		}
		cur = 0;
		md = M*M*M;
		flag = 0;
		ans = 0;
		last = 0;
		cnt = 0;
		for (i=0, p=s+6; ; i++)
		{
			if (p[i] >= '0' && p[i] <= '9')
			{
				cnt = cnt*10 + (p[i]-'0');
			}
			else
			{
				if (last)
				{
					if (!cnt)
					{
						cnt = 1;
					}
					for (j=0; j<cnt; j++)
					{
						cur = (cur*M + last) % md;
						if (flag && cur == ed)
						{
							ans++;
							flag = 0;
							cur = 0;
						}
						else if (!flag && cur == st)
						{
							flag = 1;
							cur = 0;
						}
					}
				}
				last = (p[i]-'A') + 1;
				cnt = 0;
			}
			if (!p[i])
			{
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

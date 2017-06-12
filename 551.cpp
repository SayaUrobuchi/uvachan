#include <stdio.h>

int s[100005], tbl[128];
char buf[100005];

int main()
{
	int sn, cnt;
	char *p;
	tbl['['] = 1;
	tbl['{'] = 2;
	tbl['<'] = 3;
	tbl[']'] = -1;
	tbl['}'] = -2;
	tbl['>'] = -3;
	while(gets(buf))
	{
		sn = 0;
		cnt = 1;
		for(p=buf; *p; p++, cnt++)
		{
			if(*p == '(')
			{
				if(*(p+1) == '*')
				{
					s[sn++] = 4;
					p++;
				}
				else
				{
					s[sn++] = 0;
				}
			}
			else if(tbl[*p] > 0)
			{
				s[sn++] = tbl[*p];
			}
			else if(tbl[*p] < 0)
			{
				if(!sn || s[sn-1]+tbl[*p])
				{
					break;
				}
				sn--;
			}
			else if(*p == '*' && *(p+1) == ')')
			{
				if(!sn || s[sn-1] != 4)
				{
					break;
				}
				sn--;
				p++;
			}
			else if(*p == ')')
			{
				if(!sn || s[sn-1])
				{
					break;
				}
				sn--;
			}
		}
		if(*p || sn)
		{
			printf("NO %d\n", cnt);
		}
		else
		{
			printf("YES\n");
		}
	}
	return 0;
}

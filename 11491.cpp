#include <stdio.h>

char buf[10000005], s[10000005];

int main()
{
	int n, m, sn;
	char *ptr;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		gets(buf);
		gets(buf);
		for(ptr=buf, sn=-1; *ptr; ptr++)
		{
			for(; sn>=0&&m; sn--, m--)
			{
				if(*ptr <= s[sn])
				{
					break;
				}
			}
			s[++sn] = *ptr;
		}
		s[sn-m+1] = 0;
		puts(s);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

#define M 26

char s[1024];
int tbl[32], tbl0[128];

int main()
{
	char *p;
	int i, j;
	while(gets(s))
	{
		memset(tbl, 0, sizeof(tbl));
		memset(tbl0, 0, sizeof(tbl0));
		for (p=s; *p; p++)
		{
			tbl[*p-'A']++;
		}
		for (i=0; i<M; i++)
		{
			tbl0[tbl[i]]++;
			tbl[i] = 0;
		}
		gets(s);
		for (p=s; *p; p++)
		{
			tbl[*p-'A']++;
		}
		for (i=0; i<M; i++)
		{
			tbl0[tbl[i]]--;
		}
		j = p-s;
		for (i=0; i<j; i++)
		{
			if (tbl0[i])
			{
				break;
			}
		}
		puts(i>=j ? "YES" : "NO");
	}
	return 0;
}

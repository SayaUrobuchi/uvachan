#include <stdio.h>
#include <string.h>

char s[10005];
int tbl[128], ans[128];

int main()
{
	int i, now, count;
	for (i=1, now=66; !tbl[now]; i++, now=(now*66)%100)
	{
		tbl[now] = i;
		ans[i] = now;
	}
	scanf("%d", &count);
	gets(s);
	while (count--)
	{
		gets(s);
		if (!strcmp(s, "0"))
		{
			puts("1");
		}
		else if (!strcmp(s, "1"))
		{
			puts("66");
		}
		else
		{
			now = 0;
			for (i=0; s[i]; i++)
			{
				now = (now*10 + s[i]-'0') % 5;
			}
			now = (now+3) % 5;
			printf("%d\n", ans[now+2]);
		}
	}
    return 0;
}
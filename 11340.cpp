#include <stdio.h>
#include <string.h>

int tbl[256];
char str[10001];

int main()
{
	int count, n, i, m, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(tbl, 0, sizeof(tbl));
		gets(str);
		for(i=0; i<n; i++)
		{
			gets(str);
			sscanf(str+1, "%d", &tbl[str[0]+128]);
		}
		scanf("%d", &m);
		ans = 0;
		gets(str);
		while(m--)
		{
			gets(str);
			for(i=0; str[i]; i++)
			{
				ans += tbl[str[i]+128];
			}
		}
		printf("%d.%02d$\n", ans/100, ans%100);
	}
	return 0;
}

#include <iostream>
#include <cstring>

int tbl[128];
char s[1024];

int main()
{
	int i, ans, b0, b1;
	while (scanf("%s", s) == 1)
	{
		memset(tbl, 0, sizeof(tbl));
		for (i=0; s[i]; ++i)
		{
			++tbl[s[i]];
		}
		ans = i;
		for (i='a', b0=0, b1=0; i<='z'; i++)
		{
			if (tbl[i] > b0)
			{
				b1 = b0;
				b0 = tbl[i];
			}
			else if (tbl[i] > b1)
			{
				b1 = tbl[i];
			}
		}
		printf("%d\n", ans-b0-b1);
	}
	return 0;
}

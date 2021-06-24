#include <iostream>

int ucnt, tbl[128];
char buf[128];

int main()
{
	int i;
	while (scanf("%s", buf) == 1)
	{
		++ucnt;
		for (i=0; buf[i]; i++)
		{
			if (tbl[buf[i]] == ucnt)
			{
				break;
			}
			tbl[buf[i]] = ucnt;
		}
		puts(buf[i] ? "0" : "1");
	}
	return 0;
}

#include <iostream>
#include <cstring>

int ucnt, tbl[128];
char buf[1024];

int main()
{
	int n, i, j;
	std::string best;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, best.resize(32); i<n; i++)
		{
			scanf("%s", buf);
			++ucnt;
			for (j=0; buf[j]; j++)
			{
				if (tbl[buf[j]] != ucnt)
				{
					tbl[buf[j]] = ucnt;
				}
				else
				{
					break;
				}
			}
			if (!buf[j] && j >= 5)
			{
				if (j < best.size() || (j == best.size() && strcmp(buf, best.c_str()) > 0))
				{
					best = buf;
				}
			}
		}
		if (best.size() >= 32)
		{
			puts("neibb!");
		}
		else
		{
			puts(best.c_str());
		}
	}
	return 0;
}

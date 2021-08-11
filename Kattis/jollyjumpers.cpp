#include <iostream>

int ucnt;
int tbl[1048576];

int main()
{
	int n, i, t, u, last;
	bool gg;
	while (scanf("%d%d", &n, &last) == 2)
	{
		++ucnt;
		for (i=1, gg=false; i<n; i++)
		{
			scanf("%d", &t);
			u = abs(t-last);
			if (u < 1 || u >= n || tbl[u] == ucnt)
			{
				gg = true;
			}
			else
			{
				tbl[u] = ucnt;
				last = t;
			}
		}
		puts(gg?"Not jolly":"Jolly");
	}
	return 0;
}

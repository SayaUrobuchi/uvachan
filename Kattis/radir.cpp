#include <iostream>

int ucnt;
int tbl[1024];

int main()
{
	int n, m, i, j, a, b, c, ans;
	bool found;
	while (scanf("%d%d", &n, &m) == 2)
	{
		++ucnt;
		found = false;
		for (i=0; i<n; i++)
		{
			scanf("%d%d", &a, &b);
			c = (a << 4) + b;
			tbl[c] = ucnt;
			for (j=c-2; j<=c&&!found; j++)
			{
				if (tbl[j] == tbl[j+1] && tbl[j] == tbl[j+2])
				{
					found = true;
					ans = i;
				}
			}
		}
		if (!found)
		{
			puts("neibb");
		}
		else
		{
			printf("%d\n", std::max(1, ans-m+1));
		}
	}
	return 0;
}

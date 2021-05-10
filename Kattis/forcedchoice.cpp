#include <iostream>

int main()
{
	int n, m, k, i, j, t;
	bool keep;
	while (scanf("%d%d%d", &n, &k, &m) == 3)
	{
		for (i=0; i<m; i++)
		{
			scanf("%d", &t);
			keep = false;
			while (t--)
			{
				scanf("%d", &j);
				if (j == k)
				{
					keep = true;
				}
			}
			puts(keep ? "KEEP" : "REMOVE");
		}
	}
	return 0;
}

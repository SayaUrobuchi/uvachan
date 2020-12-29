#include <iostream>
#include <unordered_map>

char nam[1024];

int main()
{
	int n, m, o, i, t, sc;
	bool gg;
	std::unordered_map<std::string, int> tbl;
	while (scanf("%d%d%d", &n, &o, &m) == 3)
	{
		for (i=0; i<n; i++)
		{
			scanf("%*s");
		}
		tbl.clear();
		gg = true;
		for (i=0; i<m; i++)
		{
			scanf("%s%d", nam, &sc);
			t = (tbl[nam] += sc);
			if (t >= o && t-sc < o)
			{
				printf("%s wins!\n", nam);
				gg = false;
			}
		}
		if (gg)
		{
			puts("No winner!");
		}
	}
	return 0;
}

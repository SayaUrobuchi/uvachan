#include <iostream>
#include <vector>

std::vector<int> v[8];

int main()
{
	int n, i, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=1; i<=6; i++)
		{
			v[i].clear();
		}
		for (i=1; i<=n; i++)
		{
			scanf("%d", &t);
			v[t].emplace_back(i);
		}
		for (i=6, t=-1; i>=1; i--)
		{
			if (v[i].size() == 1)
			{
				t = i;
				break;
			}
		}
		if (t < 0)
		{
			puts("none");
		}
		else
		{
			printf("%d\n", v[t].back());
		}
	}
	return 0;
}

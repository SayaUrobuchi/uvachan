#include <iostream>

const int MAX = 100;

std::string fiz[MAX+5];
char buf[1024];

int main()
{
	int n, m, i, j, c, best, ans;
	for (i=1; i<=MAX; i++)
	{
		if (i % 3 == 0 && i % 5 == 0)
		{
			fiz[i] = "fizzbuzz";
		}
		else if (i % 5 == 0)
		{
			fiz[i] = "buzz";
		}
		else if (i % 3 == 0)
		{
			fiz[i] = "fizz";
		}
		else
		{
			sprintf(buf, "%d", i);
			fiz[i] = buf;
		}
	}
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, best=-1; i<n; i++)
		{
			for (j=1, c=0; j<=m; j++)
			{
				scanf("%s", buf);
				if (fiz[j] == buf)
				{
					++c;
				}
			}
			if (c > best)
			{
				best = c;
				ans = i;
			}
		}
		printf("%d\n", ans+1);
	}
	return 0;
}

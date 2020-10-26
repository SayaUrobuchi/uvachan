#include <iostream>

int main()
{
	int n, i, j, k, l, t, best;
	std::string s;
	while (std::getline(std::cin, s))
	{
		n = s.size();
		for (i=2, best=n; i+i<n; i++)
		{
			for (j=0; j+i+i<=n; j++)
			{
				for (k=j+i, t=1; k+i<=n; k++)
				{
					for (l=0; l<i; l++)
					{
						if (s[j+l] != s[k+l])
						{
							break;
						}
					}
					if (l >= i)
					{
						++t;
						k += i-1;
					}
				}
				if (n+i-t*(i-1) < best)
				{
					//printf("%d %d => %d\n", i, j, t);
					best = n+i-t*(i-1);
				}
			}
		}
		printf("%d\n", best);
	}
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int n, m, i, p, q;
	scanf("%d%d", &n, &m);
	if (m < n-1 || m > (n-1)+(n-2))
	{
		puts("-1");
	}
	else
	{
		for (p=1, q=2, i=0; i<m; i++)
		{
			printf("%d %d\n", p, q);
			if (q < n)
			{
				++q;
			}
			else
			{
				++p;
			}
		}
	}
	return 0;
}

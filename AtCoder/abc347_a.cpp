#include <iostream>
using namespace std;

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	bool first = true;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (t % m == 0)
		{
			if (!first)
			{
				putchar(' ');
			}
			first = false;
			printf("%d", t / m);
		}
	}
	puts("");
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	bool first = true;
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		if (!(t & 1))
		{
			if (!first)
			{
				putchar(' ');
			}
			first = false;
			printf("%d", t);
		}
	}
	puts("");
	return 0;
}

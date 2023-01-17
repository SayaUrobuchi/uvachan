#include <iostream>
using namespace std;

int main()
{
	int n, k, i, t;
	scanf("%d%d", &n, &k);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		if (i % k == k-1)
		{
			if (i >= k)
			{
				putchar(' ');
			}
			printf("%d", t);
		}
	}
	puts("");
	return 0;
}

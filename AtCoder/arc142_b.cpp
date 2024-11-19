#include <iostream>
using namespace std;

int main()
{
	int n, i, j, k, a, b;
	scanf("%d", &n);
	for (i=1, j=1; i<=n; i++, j+=n)
	{
		printf("%d", j);
		for (a=j+1, b=j+n-1, k=1; k<n; k++)
		{
			if (k & 1)
			{
				printf(" %d", b);
				--b;
			}
			else
			{
				printf(" %d", a);
				++a;
			}
		}
		puts("");
	}
	return 0;
}
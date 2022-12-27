#include <iostream>
using namespace std;

int deg[64];

int main()
{
	int n, m, i, a, b;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		++deg[a];
		++deg[b];
	}
	for (i=1; i<=n; i++)
	{
		printf("%d\n", deg[i]);
	}
	return 0;
}
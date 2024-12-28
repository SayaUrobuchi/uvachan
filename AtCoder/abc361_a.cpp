#include <iostream>
using namespace std;

int main()
{
	int n, m, o, i;
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		printf("%d ", t);
	}
	printf("%d", o);
	for (; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		printf(" %d", t);
	}
	puts("");
	return 0;
}

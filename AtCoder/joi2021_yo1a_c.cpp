#include <iostream>
using namespace std;

const int M = 105;

int tbl[M];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%d", &t);
		tbl[t] |= 1;
	}
	for (i=0; i<m; i++)
	{
		int t;
		scanf("%d", &t);
		tbl[t] |= 2;
	}
	for (i=0; i<=100; i++)
	{
		if (tbl[i] == 3)
		{
			printf("%d\n", i);
		}
	}
	return 0;
}

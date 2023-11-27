#include <iostream>
using namespace std;

const int N = 16384;

int ary[N], bry[N], cry[N];

int main()
{
	int n, i, j, k, t;
	scanf("%d", &n);
	for (i=1, k=0; i<=n; i++)
	{
		for (j=1; j<=n; j++)
		{
			scanf("%d", &t);
			if (t != -1)
			{
				ary[k] = i;
				bry[k] = j;
				cry[k] = t;
				++k;
			}
		}
	}
	printf("%d\n", k);
	for (i=0; i<k; i++)
	{
		printf("%d %d %d\n", ary[i], bry[i], cry[i]);
	}
	return 0;
}

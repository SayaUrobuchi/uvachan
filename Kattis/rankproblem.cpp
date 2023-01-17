#include <iostream>
using namespace std;

const int N = 105;

int ary[N], rnk[N];

int main()
{
	int n, m, i, j, a, b;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		rnk[i] = i;
		ary[i] = i;
	}
	for (i=0; i<m; i++)
	{
		scanf(" T%d T%d", &a, &b);
		if (rnk[a] > rnk[b])
		{
			for (j=rnk[b]; j<rnk[a]; j++)
			{
				ary[j] = ary[j+1];
				rnk[ary[j]] = j;
			}
			ary[j] = b;
			rnk[b] = j;
		}
	}
	for (i=1; i<=n; i++)
	{
		if (i != 1)
		{
			putchar(' ');
		}
		printf("T%d", ary[i]);
	}
	puts("");
	return 0;
}

#include <iostream>
#include <algorithm>
using namespace std;

int ary[10][10], bry[10][10], cry[10];

int main()
{
	int n, m, i, j, a, b;
	bool same, gg;
	scanf("%d%d", &n, &m);
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		ary[a][b] = ary[b][a] = 1;
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &a, &b);
		bry[a][b] = bry[b][a] = 1;
	}
	for (i=1; i<=n; i++)
	{
		cry[i-1] = i;
	}
	same = false;
	do
	{
		for (i=1, gg=false; i<=n&&!gg; i++)
		{
			for (j=1; j<=n&&!gg; j++)
			{
				if (ary[i][j] != bry[cry[i-1]][cry[j-1]])
				{
					gg = true;
				}
			}
		}
		if (!gg)
		{
			same = true;
			break;
		}
	}while (next_permutation(cry, cry+n));
	if (same)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
#include <iostream>
#include <cstring>
using namespace std;

int row[2048], col[2048];
int ary[2048][2048];

int main()
{
	int n, m, i, j;
	while (scanf("%d%d", &n, &m) == 2)
	{
		memset(row, 0, sizeof(row));
		memset(col, 0, sizeof(col));
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				scanf("%d", &ary[i][j]);
				row[i] += ary[i][j];
				col[j] += ary[i][j];
			}
		}
		for (i=0; i<n; i++)
		{
			for (j=0; j<m; j++)
			{
				printf("%s%d", j?" ":"", row[i]+col[j]-ary[i][j]);
			}
			puts("");
		}
	}
	return 0;
}

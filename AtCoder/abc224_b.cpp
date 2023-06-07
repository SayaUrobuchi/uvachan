#include <iostream>
using namespace std;

int ary[64][64];

int main()
{
	int n, m, i, j, a, b, c, d;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			scanf("%d", &ary[i][j]);
		}
	}
	bool gg = false;
	for (a=0; a<n&&!gg; a++)
	{
		for (b=a+1; b<n&&!gg; b++)
		{
			for (c=0; c<m&&!gg; c++)
			{
				for (d=c+1; d<m&&!gg; d++)
				{
					if (ary[a][c] + ary[b][d] > ary[a][d] + ary[b][c])
					{
						gg = true;
					}
				}
			}
		}
	}
	puts(gg ? "No" : "Yes");
	return 0;
}

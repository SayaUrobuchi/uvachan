#include <iostream>
using namespace std;

int DX[] = {0, 1, 0, -1};
int DY[] = {1, 0, -1, 0};

int ary[55][55];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	int x = 0;
	int y = -1;
	int t, d, u;
	ary[0][0] = 1;
	for (t=1, d=0, u=n; t<=n*n; d=(d+1)&3)
	{
		for (i=0; i<u; i++, t++)
		{
			x += DX[d];
			y += DY[d];
			ary[x][y] = t;
		}
		u -= 1 - (d & 1);
	}
	for (i=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if (i == x && j == y)
			{
				printf("T");
			}
			else
			{
				printf("%d", ary[i][j]);
			}
			if (j == n-1)
			{
				puts("");
			}
			else
			{
				putchar(' ');
			}
		}
	}
	return 0;
}

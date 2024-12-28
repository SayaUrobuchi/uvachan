#include <iostream>
using namespace std;

int main()
{
	int x, y, i, j;
	int ary[4][4];
	scanf("%d%d", &x, &y);
	for (i=1; i<=2; i++)
	{
		for (j=1; j<=2; j++)
		{
			scanf("%d", &ary[i][j]);
		}
	}
	printf("%d\n", ary[x][y]);
	return 0;
}

#include <iostream>
using namespace std;

int ary[4][4];

int mid(int t)
{
	return ary[0][t] + ary[1][t] + ary[2][t]
		 - min(ary[0][t], min(ary[1][t], ary[2][t]))
		 - max(ary[0][t], max(ary[1][t], ary[2][t]));
}

int main()
{
	int i, j;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			scanf("%d", &ary[i][j]);
		}
	}
	printf("%d %d %d\n", mid(0), mid(1), mid(2));
	return 0;
}
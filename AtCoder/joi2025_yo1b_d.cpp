#include <iostream>
using namespace std;

const int N = 16;

int ary[N][N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[0][i]);
	}
	for (i=1; i<n; i++)
	{
		for (j=0; j<n-i; j++)
		{
			ary[i][j] = ary[i-1][j] + ary[i-1][j+1];
			printf("%d%c", ary[i][j], " \n"[j+1>=n-i]);
		}
	}
	return 0;
}
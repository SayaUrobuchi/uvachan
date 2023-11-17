#include <iostream>
using namespace std;
 
const int N = 1005;
const char TREE = '*';
 
int sum[N][N];
char s[N+5];
 
int main()
{
	int n, m, i, j, a, b, c, d;
	scanf("%d%d", &n, &m);
	for (i=1; i<=n; i++)
	{
		scanf("%s", s+1);
		for (j=1; j<=n; j++)
		{
			sum[i][j] = sum[i-1][j] + sum[i][j-1]
					  - sum[i-1][j-1] + (s[j] == TREE);
		}
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d%d%d", &a, &b, &c, &d);
		int res = sum[c][d] - sum[c][b-1]
				- sum[a-1][d] + sum[a-1][b-1];
		printf("%d\n", res);
	}
	return 0;
}
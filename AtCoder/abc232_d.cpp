#include <iostream>
using namespace std;

bool can[105][105];
char board[105][105];

int main()
{
	int n, m, i, j, ans;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		scanf("%s", board[i]);
	}
	can[0][0] = true;
	for (i=0, ans=0; i<n; i++)
	{
		for (j=0; j<n; j++)
		{
			if ((i || j) && board[i][j] == '.')
			{
				if (i && can[i-1][j])
				{
					can[i][j] = true;
				}
				if (j && can[i][j-1])
				{
					can[i][j] = true;
				}
				if (can[i][j])
				{
					ans = max(ans, i+j);
				}
			}
		}
	}
	printf("%d\n", ans+1);
	return 0;
}
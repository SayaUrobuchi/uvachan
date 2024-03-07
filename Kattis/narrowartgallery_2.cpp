#include <iostream>
#include <cstring>
using namespace std;

const int N = 256;

int n, m;
int ary[N], bry[N];
int cnt[4] = {0, 1, 1, 2};
int dp[N][N][4];
bool used[N][N][4];

int recurs(int i, int j, int k)
{
	if (j < 0)
	{
		return -1e9;
	}
	if (used[i][j][k])
	{
		return dp[i][j][k];
	}
	used[i][j][k] = true;
	if (i == 0)
	{
		return dp[i][j][k] = (-1e9) * (j != 0);
	}
	int t;
	int a = ary[i];
	int b = bry[i];
	dp[i][j][k] = -1e9;
	for (t=0; t<3; t++)
	{
		if ((t | k) < 3)
		{
			dp[i][j][k] = max(dp[i][j][k], recurs(i-1, j-cnt[k], t));
		}
	}
	int sel = (~k & 3);
	dp[i][j][k] += ary[i] * (sel & 1) + bry[i] * (sel >> 1);
    return dp[i][j][k];
}

int main()
{
    int i;
    while (scanf("%d%d", &n, &m) == 2)
    {
        if (n == 0 && m == 0)
        {
            break;
        }
        for (i=1; i<=n; i++)
        {
            scanf("%d%d", &ary[i], &bry[i]);
        }
        printf("%d\n", max(recurs(n, m, 0), 
        				   max(recurs(n, m, 1), recurs(n, m, 2))
        				  ));
    }
    return 0;
}
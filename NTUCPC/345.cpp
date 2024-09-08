#include <iostream>
using namespace std;

const int M = 1000000007;
const int N = 100005;

// dp[i][j][k] 到第 i 天時，已連續吃 j 次，k 表是否曾連吃 3 次
int dp[N][3][2];
// 另解用
int comp[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	dp[0][0][0] = 1;
	for (i=1; i<=n; i++)
	{
		// 連續 0 次可由 0~2 任意次數停下休息而來
		dp[i][0][0] = dp[i-1][0][0];
		dp[i][0][1] = dp[i-1][0][1];
		for (j=1; j<=2; j++)
		{
			dp[i][0][0] = (dp[i][0][0] + dp[i-1][j][0]) % M;
			dp[i][0][1] = (dp[i][0][1] + dp[i-1][j][1]) % M;
		}
		// 連續 1、2 次只可由連續少 1 次而來
		for (j=1; j<=2; j++)
		{
			dp[i][j][0] = dp[i-1][j-1][0];
			dp[i][j][1] = dp[i-1][j-1][1];
		}
		// 連續 2 次以上直接看成 2 次即可，反正沒影響了
		// 未達成連 3 次的則可由連 2 次來達成
		dp[i][2][1] = (dp[i][2][1] + dp[i-1][2][0]) % M;
		dp[i][2][1] = (dp[i][2][1] + dp[i-1][2][1]) % M;
		// 另解：將第 i-1 天或以前達成的乘以 2（吃或不吃）
		// 加上第 i 天初達成的也可以，達成後分配就不重要了
		comp[i] = (comp[i-1] << 1) % M;
		comp[i] = (comp[i] + dp[i-1][2][0]) % M;
	}
	int ans = 0;
	for (i=0; i<=2; i++)
	{
		ans = (ans + dp[n][i][1]) % M;
	}
	printf("%d\n", ans);
	// 另解用
	//printf("%d\n", comp[n]);
	return 0;
}

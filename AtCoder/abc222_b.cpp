// Problem: B - Failing Grade
// Contest: AtCoder - エクサウィザーズプログラミングコンテスト2021（AtCoder Beginner Contest 222）
// URL: https://atcoder.jp/contests/abc222/tasks/abc222_b
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

#include <iostream>
using namespace std;

int main()
{
	int n, m, i, t, ans;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, ans=0; i<n; i++)
		{
			scanf("%d", &t);
			ans += (t < m);
		}
		printf("%d\n", ans);
	}
	return 0;
}
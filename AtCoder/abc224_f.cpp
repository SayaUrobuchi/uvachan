#include <iostream>
using namespace std;

const int N = 200005;
const int M = 998244353;

char s[N];
int dp[N], dp2[N];

int main()
{
	int i, t, u, su;
	scanf("%s", s+1);
	dp[0] = 0;
	for (i=1, t=0, u=1, su=0; s[i]; i++)
	{
		if (i > 2)
		{
			u = (u << 1) % M;
		}
		su = (su + u) % M;
		t = ((long long)t * 10 + (s[i]-'0') * (long long)su) % M;
		dp[i] = (dp2[i-1] + t) % M;
		dp2[i] = ((long long)dp[i] + dp2[i-1]) % M;
	}
	printf("%d\n", dp[i-1]);
	return 0;
}

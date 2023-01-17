#include <iostream>
#include <algorithm>
using namespace std;

int tbl[32];
int dp[64], len[64];
char buf[32768];

int main()
{
	int i, j, k, cnt, ans;
	dp[1] = 1;
	dp[3] = 2;
	len[0] = 1;
	len[1] = 3;
	len[2] = 3;
	for (i=4, j=3; j<26; i++)
	{
		dp[i] = dp[i-2] + dp[i-4];
		for (k=0; k<dp[i]; k++, j++)
		{
			len[j] = i;
		}
	}
	fgets(buf, sizeof(buf), stdin);
	for (i=0, cnt=0; buf[i]>=' '; i++)
	{
		if (buf[i] >= 'a' && buf[i] <= 'z')
		{
			++tbl[(buf[i]^32^64)-1];
			++cnt;
		}
		else if (buf[i] >= 'A' && buf[i] <= 'Z')
		{
			++tbl[(buf[i]^64)-1];
			++cnt;
		}
	}
	sort(tbl, tbl+26, greater<int>());
	for (i=0, ans=(cnt-1)*3; i<26; i++)
	{
		ans += tbl[i] * len[i];
	}
	printf("%d\n", ans);
	return 0;
}

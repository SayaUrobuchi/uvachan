#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int INFI = 1e9;

pp ary[1000005], stk[1000005];
bool used[1000005];
int dp[1000005], block[2][1000005];
char sep[8];

int recurs(int pos)
{
	int i;
	if (used[pos])
	{
		return dp[pos];
	}
	used[pos] = true;
	dp[pos] = INFI;
	for (i=0; i<2; i++)
	{
		if (block[i][pos] != -1)
		{
			dp[pos] = min(dp[pos], recurs(block[i][pos])+1);
		}
	}
	if (dp[pos] == INFI)
	{
		dp[pos] = 0;
	}
	return dp[pos];
}

int main()
{
	int n, i, sid, idx, sn;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i].first);
		ary[i].second = i;
	}
	for (sid=0; sid<=1; sid++)
	{
		stk[0] = {2e9, -1};
		sn = 0;
		for (i=0; i<n; i++)
		{
			idx = ary[i].second;
			for (; sn>0&&ary[i].first>=stk[sn].first; --sn);
			block[sid][idx] = stk[sn].second;
			stk[++sn] = ary[i];
		}
		reverse(ary, ary+n);
	}
	for (i=0; i<n; i++)
	{
		printf("%s%d", sep, recurs(i));
		*sep = ' ';
	}
	puts("");
	return 0;
}
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 128;
const int MAXM = 10005;

int ary[N], bry[N];
int dp[MAXM];

int main()
{
	int n, m, c, i, j, k, t, cur, ans;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &ary[i]);
	}
	for (i=1; i<MAXM; i++)
	{
		for (j=0, k=0; j<n; j++)
		{
			if (i >= ary[j])
			{
				bry[k++] = dp[i-ary[j]];
			}
		}
		sort(bry, bry+k);
		for (j=0, cur=0; j<k; j++)
		{
			if (bry[j] == cur)
			{
				++cur;
			}
			else if (bry[j] > cur)
			{
				break;
			}
		}
		dp[i] = cur;
	}
	scanf("%d", &m);
	for (i=0; i<m; i++)
	{
		scanf("%d", &c);
		for (j=0, ans=0; j<c; j++)
		{
			scanf("%d", &t);
			ans ^= dp[t];
		}
		putchar(ans?'W':'L');
	}
	puts("");
	return 0;
}

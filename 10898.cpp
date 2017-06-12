#include <stdio.h>
#include <string.h>

#define INFINITY 2000000000

int n, m;
int sprice[10], price[10];
int item[10][10], st[10];
int dp[1000000];
char used[1000000];

int recursion(int state)
{
	int i, j;
	char buf[7];
	/*printf("%d\n", state);*/
	if(used[state])
	{
		return dp[state];
	}
	used[state] = 1;
	if(!state)
	{
		return dp[state]=0;
	}
	dp[state] = INFINITY;
	sprintf(buf, "%0*d", n, state);
	for(i=n-1, j=1; i>=0; i--, j*=10)
	{
		if(buf[i] > '0')
		{
			if(recursion(state-j) + sprice[n-i-1] < dp[state])
			{
				dp[state] = dp[state-j] + sprice[n-i-1];
			}
		}
	}
	for(i=0; i<m; i++)
	{
		for(j=0; j<n; j++)
		{
			if(buf[j] < '0' + item[i][n-j-1])
			{
				break;
			}
		}
		if(j == n)
		{
			if(recursion(state-st[i]) + price[i] < dp[state])
			{
				dp[state] = dp[state-st[i]] + price[i];
			}
		}
	}
	return dp[state];
}

int main()
{
	int i, j, o, state, need;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &sprice[i]);
		}
		scanf("%d", &m);
		for(i=0; i<m; i++)
		{
			for(j=0, state=0, o=1; j<n; j++, o*=10)
			{
				scanf("%d", &item[i][j]);
				state += item[i][j] * o;
			}
			st[i] = state;
			/*printf("%d\n", state);*/
			scanf("%d", &price[i]);
		}
		scanf("%d", &o);
		while(o--)
		{
			for(i=0, state=0, j=1; i<n; i++, j*=10)
			{
				scanf("%d", &need);
				state += need * j;
			}
			/*printf("XDDDSTATE %d\n", state);*/
			memset(used, 0, sizeof(used));
			printf("%d\n", recursion(state));
		}
	}
	return 0;
}

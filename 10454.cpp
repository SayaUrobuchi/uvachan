#include <stdio.h>
#include <string.h>

long long dp[150][150];
int parsis[150];
int next[150];
char str[150];

long long recursion(int left, int right)
{
	int i, prio;
	if(left >= right)
	{
		return 1;
	}
	if(dp[left][right])
	{
		return dp[left][right];
	}
	for(i=left, prio=0; i<=right; i=next[i])
	{
		if(str[i] == '+')
		{
			prio = 2;
		}
		else if(str[i] == '*' && prio != 2)
		{
			prio = 1;
		}
	}
	if(!prio)
	{
		return dp[left][right]=recursion(left+1, right-1);
	}
	else if(prio == 1)
	{
		for(i=left; i<=right; i=next[i])
		{
			if(str[i] == '*')
			{
				dp[left][right] += recursion(left, i-1) * recursion(i+1, right);
			}
		}
	}
	else
	{
		for(i=left; i<=right; i=next[i])
		{
			if(str[i] == '+')
			{
				dp[left][right] += recursion(left, i-1) * recursion(i+1, right);
			}
		}
	}
	return dp[left][right];
}

int main()
{
	int i, j, par;
	while(gets(str))
	{
		for(i=0, j=0, par=0; str[i]; i++)
		{
			if(str[i] == '(')
			{
				parsis[par++] = j;
				str[j++] = str[i];
			}
			else if(str[i] == ')')
			{
				next[parsis[--par]] = j;
				next[j] = j + 1;
				str[j++] = str[i];
			}
			else if(str[i] == '+' || str[i] == '*')
			{
				next[j] = j + 1;
				str[j++] = str[i];
			}
		}
		memset(dp, 0, sizeof(dp));
		printf("%lld\n", recursion(0, j-1));
	}
	return 0;
}

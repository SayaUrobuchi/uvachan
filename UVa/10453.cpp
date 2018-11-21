#include <stdio.h>
#include <string.h>

int dp[1000][1000];
int last[1000][1000];
int chk[1000][1000];
char str[1001];

int recursion(int left, int right)
{
	if(chk[left][right])
	{
		return dp[left][right];
	}
	chk[left][right] = 1;
	if(right - left < 1)
	{
		return dp[left][right] = 0;
	}
	if(str[left] == str[right])
	{
		dp[left][right] = recursion(left+1, right-1);
	}
	else
	{
		if(recursion(left+1, right) < recursion(left, right-1))
		{
			dp[left][right] = dp[left+1][right] + 1;
			last[left][right] = 0;
		}
		else
		{
			dp[left][right] = dp[left][right-1] + 1;
			last[left][right] = 1;
		}
	}
	return dp[left][right];
}

void backtracing(int left, int right)
{
	if(left > right)
	{
		return;
	}
	if(left == right)
	{
		printf("%c", str[left]);
		return;
	}
	if(str[left] == str[right])
	{
		printf("%c", str[left]);
		backtracing(left+1, right-1);
		printf("%c", str[right]);
	}
	else
	{
		if(last[left][right])
		{
			printf("%c", str[right]);
			backtracing(left, right-1);
			printf("%c", str[right]);
		}
		else
		{
			printf("%c", str[left]);
			backtracing(left+1, right);
			printf("%c", str[left]);
		}
	}
}

int main()
{
	int len;
	while(gets(str))
	{
		memset(chk, 0, sizeof(chk));
		len = strlen(str);
		printf("%d ", recursion(0, len-1));
		backtracing(0, len-1);
		printf("\n");
	}
	return 0;
}

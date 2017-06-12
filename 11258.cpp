#include <stdio.h>
#include <string.h>

int len;
int chk[300];
long long dp[300];
char str[300];

long long recursion(int left)
{
	int i;
	long long temp, result;
	if(chk[left])
	{
		return chk[left];
	}
	chk[left] = 1;
	if(left >= len)
	{
		return dp[left] = 0;
	}
	if(left == len - 1)
	{
		return dp[left] = str[left] - 48;
	}
	if(str[left] == '0')
	{
		return dp[left] = recursion(left+1);
	}
	for(i=left, temp=0, result=0; i<len; i++)
	{
		temp *= 10;
		temp += str[i] - 48;
		if(temp > 2147483647)
		{
			break;
		}
		recursion(i+1);
		if(temp + dp[i+1] > result)
		{
			result = temp + dp[i+1];
		}
	}
	return dp[left] = result;
}

int main()
{
	int count;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		len = strlen(str);
		memset(chk, 0, sizeof(chk));
		recursion(0);
		printf("%lld\n", dp[0]);
	}
	return 0;
}

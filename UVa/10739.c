#include <stdio.h>
#include <string.h>

int dp[1000][1000];
char chk[1000][1000], str[1001];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int recursion(int left, int right)
{
	int temp;
	if(left > right)
	{
		return 0;
	}
	if(chk[left][right])
	{
		return dp[left][right];
	}
	if(str[left] == str[right])
	{
		return dp[left][right] = recursion(left+1, right-1);
	}
	else
	{
		temp = recursion(left+1, right)+1;
		temp = min(temp, recursion(left, right-1)+1);
		temp = min(temp, recursion(left+1, right-1)+1);
		chk[left][right] = 1;
		return dp[left][right] = temp;
	}
}

int main()
{
	int cas, count;
	cas = 0;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(str);
		memset(chk, 0, sizeof(chk));
		printf("Case %d: %d\n", ++cas, recursion(0, strlen(str)-1));
	}
	return 0;
}

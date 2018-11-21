#include <stdio.h>
#include <string.h>

int dp[100][100][100];
int chk[100][100][100];
char str[1000];

int recursion(int now, int left, int right)
{
	int i, num;
	char opera;
	if(chk[now][left][right])
	{
		return dp[now][left][right];
	}
	chk[now][left][right] = 1;
	/*printf("%d %d %d\n", now, left, right);*/
	sscanf(str+left, "%d%c", &num, &opera);
	for(i=left+2; i<=right; i++)
	{
		if(str[i] == '[')
		{
			break;
		}
	}
	if(opera == ']')
	{
		return dp[now][left][right]=num;
	}
	else
	{
		if(opera == '+')
		{
			if(now == 1)
			{
				return dp[now][left][right]=num;
			}
			else
			{
				return dp[now][left][right]=recursion(now-1, left, right)+recursion(now-1, i+1, right);
			}
		}
		else
		{
			if(now == 1)
			{
				return dp[now][left][right]=num*recursion(1, i+1, right);
			}
			else
			{
				return dp[now][left][right]=recursion(now-1, left, right)*recursion(now, i+1, right);
			}
		}
	}
}

int main()
{
	int n, i, len;
	while(scanf("%s%d", str, &n) == 2)
	{
		memset(chk, 0, sizeof(chk));
		printf("%d", recursion(1, 1, len=strlen(str)));
		for(i=2; i<=n; i++)
		{
			printf(" %d", recursion(i, 1, len));
		}
		printf("\n");
	}
	return 0;
}

/*
	ID: sa072682
	LANG: C
	TASK: zerosum
*/
#include <stdio.h>

char str[] = {"1 2 3 4 5 6 7 8 9"};

void dfs(int depth, int lim)
{
	int i, len, res, op, num;
	len = depth + depth - 1;
	if(depth == lim)
	{
		for(i=0, res=0, op='+', num=0; i<=len; i++)
		{
			if(i % 2)
			{
				if(str[i] != 32)
				{
					if(op == '+')
					{
						res += num;
					}
					else
					{
						res -= num;
					}
					op = str[i];
					num = 0;
				}
			}
			else
			{
				num *= 10;
				num += str[i] - 48;
			}
		}
		if(res == 0)
		{
			printf("%s\n", str);
		}
		return;
	}
	str[len] = 32;
	dfs(depth+1, lim);
	str[len] = '+';
	dfs(depth+1, lim);
	str[len] = '-';
	dfs(depth+1, lim);
}

int main()
{
	int n;
	freopen("zerosum.in", "r", stdin);
	freopen("zerosum.out", "w", stdout);
	scanf("%d", &n);
	str[n+n-1] = 0;
	dfs(1, n);
	scanf(" ");
	return 0;
}

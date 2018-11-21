#include <stdio.h>
#include <string.h>

int n, m, count;
char size1[30], size2[30], used[6][6], cost[6], check[6], check2[30];

int trans(char* str)
{
	if(str[0] == 'L') return 0;
	if(str[0] == 'M') return 1;
	if(str[0] == 'S') return 2;
	if(str[1] == 'X') return 3;
	if(str[1] == 'L') return 4;
	return 5;
}

char checksuit(char);

char checksuit2(char pre, char now)
{
	char i, tmp, *ptr;
	check[now] = 0;
	tmp = cost[now];
	for(i=0; i<tmp; i++)
	{
		ptr = &used[now][i];
		if(check2[*ptr] && checksuit(*ptr))
		{
			*ptr = pre;
			return 1;
		}
	}
	return 0;
}

char checksuit(char now)
{
	char i, size;
	size = size1[now];
	check2[now] = 0;
	if(cost[size] != n)
	{
		used[size][cost[size]++] = now;
		return 1;
	}
	else if(check[size] && checksuit2(now, size))
	{
		return 1;
	}
	size = size2[now];
	if(cost[size] != n)
	{
		used[size][cost[size]++] = now;
		return 1;
	}
	else if(check[size] && checksuit2(now, size))
	{
		return 1;
	}
	return 0;
}

int main()
{
	char i, s1[5], s2[5], ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		n /= 6;
		memset(cost, 0, 6);
		for(i=0, ans=1; i<m; i++)
		{
			memset(check, 1, 6);
			memset(check2, 1, i + 1);
			scanf("%s%s", s1, s2);
			if(ans)
			{
				size1[i] = trans(s1);
				size2[i] = trans(s2);
				ans = checksuit(i);
			}
		}
		if(ans) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}

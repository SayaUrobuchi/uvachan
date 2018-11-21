#include <stdio.h>
#include <string.h>

int c;
char str[50];

int chk(int len)
{
	int i, j;
	for(i=2, j=1; i<=len; i+=3, j++)
	{
		if(!strncmp(str+len-j+1, str+len-j-j+1, j) && !strncmp(str+len-j+1, str+len-j-j-j+1, j))
		{
			break;
		}
	}
	return i > len;
}

void dfs(int depth)
{
	if(!str[depth])
	{
		c++;
		return;
	}
	if(str[depth] == '*')
	{
		str[depth] = '0';
		if(chk(depth))
		{
			dfs(depth+1);
		}
		str[depth] = '1';
		if(chk(depth))
		{
			dfs(depth+1);
		}
		str[depth] = '*';
	}
	else
	{
		if(chk(depth))
		{
			dfs(depth+1);
		}
	}
}

int main()
{
	int cas, n;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		scanf("%s", str);
		c = 0;
		dfs(0);
		printf("Case %d: %d\n", ++cas, c);
	}
	return 0;
}

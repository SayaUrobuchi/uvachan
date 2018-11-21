#include <stdio.h>

int n;
char s[100005];

void dfs(int depth)
{
	if(depth == n)
	{
		s[n] = 0;
		printf("%s\n", s);
		return;
	}
	s[depth] = '0';
	dfs(depth+1);
	s[depth] = '1';
	dfs(depth+1);
}

int main()
{
	while(scanf("%d", &n) == 1)
	{
		dfs(0);
	}
	return 0;
}

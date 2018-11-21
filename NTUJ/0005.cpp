#include <stdio.h>

int n, ans;
char ary[105][20], str[20], *p, *q;

void checkans()
{
	int i;
	char *ptr, *p2;
	for(i=1; i<n; i++)
	{
		for(ptr=ary[i], p2=str; *ptr&&*p2; p2+=(*p2==*ptr), ptr++);
		if(*p2)
		{
			return;
		}
	}
	if(q-str > ans)
	{
		ans = q-str;
	}
}

void dfs(int depth)
{
	*q = 0;
	checkans();
	if(p[depth] == 0)
	{
		return;
	}
	*(q++) = p[depth];
	dfs(depth+1);
	q--;
	dfs(depth+1);
}

int main()
{
	int i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", ary[i]);
		}
		p = ary[0];
		q = str;
		ans = -1;
		dfs(0);
		printf("%d\n", ans);
	}
	return 0;
}

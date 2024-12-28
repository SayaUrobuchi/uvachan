/*
	ID: sa072682
	LANG: C
	TASK: checker
*/
#include <stdio.h>
#include <string.h>

int list[14], link[15], count, n;
char chk[30], chk2[30];

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

void dfs(int depth)
{
	int i, j;
	if(depth == n)
	{
		if(count++ > 2)
		{
			return;
		}
		printf("%d", list[0]);
		for(i=1; i<n; i++)
		{
			printf(" %d", list[i]);
		}
		printf("\n");
		return;
	}
	for(i=0; link[i]; i=link[i])
	{
		if(chk[link[i]-depth+15] && chk2[link[i]+depth])
		{
			list[depth] = link[i];
			link[i] = link[j=link[i]];
			chk[j-depth+15] = chk2[j+depth] = 0;
			dfs(depth+1);
			chk[j-depth+15] = chk2[j+depth] = 1;
			link[i] = j;
		}
	}
}

int main()
{
	int i, j;
	freopen("checker.in", "r", stdin);
	freopen("checker.out", "w", stdout);
	scanf("%d", &n);
	memset(chk, 1, sizeof(chk));
	memset(chk2, 1, sizeof(chk2));
	for(i=0; i<n; i++)
	{
		link[i] = i+1;
	}
	link[i] = 0;
	if(n > 6)
	{
		for(i=0; i<n/2; i++)
		{
			link[i] = link[i+1];
			list[0] = i+1;
			chk[i+16] = chk2[i+1] = 0;
			dfs(1);
			chk[i+16] = chk2[i+1] = 1;
			link[i] = i+1;
		}
		count *= 2;
		if(n % 2)
		{
			link[n/2] = link[n/2+1];
			list[0] = n / 2 + 1;
			chk[list[0]+15] = chk2[list[0]] = 0;
			dfs(1);
		}
	}
	else
	{
		dfs(0);
	}
	printf("%d\n", count);
	return 0;
}

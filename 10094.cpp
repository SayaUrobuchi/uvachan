#include <stdio.h>
#include <string.h>

int n;
int list[1001];
int next[1001];
int chk1[2005], chk2[2005];

int dfs(int depth)
{
	int i, j, temp1, temp2;
	if(depth == n)
	{
		printf("%d", list[0]);
		for(i=1; i<n; i++)
		{
			printf(" %d", list[i]);
		}
		printf("\n");
		return 1;
	}
	for(i=0; j=next[i]; i=j)
	{
		if(!chk1[temp1=depth+j] && !chk2[temp2=j-depth+n])
		{
			chk1[temp1] = 1;
			chk2[temp2] = 1;
			list[depth] = j;
			next[i] = next[j];
			if(dfs(depth+1))
			{
				return 1;
			}
			next[i] = j;
			chk1[temp1] = 0;
			chk2[temp2] = 0;
		}
	}
	return 0;
}

int main()
{
	int i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			next[i] = i + 1;
		}
		memset(chk1, 0, sizeof(chk1));
		memset(chk2, 0, sizeof(chk2));
		if(!dfs(0))
		{
			printf("Impossible\n");
		}
	}
	return 0;
}

/*
	ID: sa072682
	LANG: C
	TASK: holstein
*/
#include <stdio.h>

int need[30], queue[65536][25], back[65536], next[65536];

void backtracing(int now, int depth)
{
	if(back[now] == -1)
	{
		printf("%d %d", depth, next[now]);
		return;
	}
	backtracing(back[now], depth+1);
	printf(" %d", next[now]);
}

int main()
{
	int n, m, i, j, k, p, q;
	char ans;
	freopen("holstein.in", "r", stdin);
	freopen("holstein.out", "w", stdout);
	scanf("%d", &m);
	for(i=0; i<m; i++)
	{
		scanf("%d", &need[i]);
	}
	scanf("%d", &n);
	for(i=0; i<n; i++)
	{
		for(j=0, ans=1; j<m; j++)
		{
			scanf("%d", &queue[i][j]);
			if(queue[i][j] < need[j])
			{
				ans = 0;
			}
		}
		if(ans)
		{
			printf("1 %d\n", i+1);
			break;
		}
		back[i] = -1;
		next[i] = i + 1;
	}
	if(!ans)
	{
		for(i=0, j=n; i<j; i++)
		{
			for(p=next[i]; p<n; p++)
			{
				for(q=0, ans=1; q<m; q++)
				{
					queue[j][q] = queue[i][q] + queue[p][q];
					if(queue[j][q] < need[q])
					{
						ans = 0;
					}
				}
				back[j] = i;
				next[j] = p + 1;
				if(ans)
				{
					backtracing(j, 1);
					printf("\n");
					break;
				}
				j++;
			}
			if(p < n)
			{
				break;
			}
		}
	}
	scanf(" ");
	return 0;
}

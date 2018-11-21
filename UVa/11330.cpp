#include <stdio.h>
#include <string.h>

int ans;
int tbl[10001];
int appear[10001];

void trans(int now, int depth)
{
	int temp;
	temp = tbl[now];
	tbl[now] = tbl[temp];
	tbl[temp] = temp;
	if(tbl[now] == now)
	{
		ans += depth;
	}
	else
	{
		trans(now, depth+1);
	}
}

int main()
{
	int count, n, i, p, q;
	scanf("%d", &count);
	while(count--)
	{
		memset(appear, 0, sizeof(appear));
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			tbl[p] = q;
			appear[p] = appear[q] = 1;
		}
		for(i=0, ans=0; i<=10000; i++)
		{
			if(appear[i] && tbl[i] != i)
			{
				trans(i, 1);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

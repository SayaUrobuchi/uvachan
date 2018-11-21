#include <stdio.h>

int n, m, ans;
int ex[20], ey[20], er[20], bx[20], by[20], br[20], stat[20];

void dfs(int now, int num, int s)
{
	if(now == n)
	{
		if(s == ((1<<m)-1))
		{
			if(num < ans)
			{
				ans = num;
			}
		}
		return;
	}
	dfs(now+1, num, s);
	dfs(now+1, num+1, s|stat[now]);
}

int main()
{
	int count, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &bx[i], &by[i], &br[i]);
			stat[i] = 0;
		}
		for(i=0; i<m; i++)
		{
			scanf("%d%d%d", &ex[i], &ey[i], &er[i]);
			for(j=0; j<n; j++)
			{
				if((long long)(bx[j]-ex[i])*(bx[j]-ex[i])+(long long)(by[j]-ey[i])*(by[j]-ey[i])<=(long long)(br[j]+er[i])*(br[j]+er[i]))
				{
					stat[j] += (1<<i);
				}
			}
		}
		ans = 100;
		dfs(0, 0, 0);
		if(ans == 100)
		{
			printf("Impossible\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int map[101][101];
int queue1[10000], queue2[10000];
int step[10000];
int chk[101][101];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int main()
{
	int cas, n, i, j, s, t1, t2, next1, next2, target;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			for(j=1; j<=n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		scanf("%d%d%d", &t1, &t2, &target);
		queue1[0] = min(t1, t2);
		queue2[0] = max(t1, t2);
		step[0] = 0;
		memset(chk, 0, sizeof(chk));
		chk[queue1[0]][queue2[0]] = 1;
		for(i=0, j=1; i<j; i++)
		{
			t1 = queue1[i];
			t2 = queue2[i];
			s = step[i] + 1;
			if(map[t1][t2])
			{
				next1 = min(map[t1][t2], t2);
				next2 = max(map[t1][t2], t2);
				if(!chk[next1][next2])
				{
					if(next1 == target || next2 == target)
					{
						break;
					}
					chk[next1][next2] = 1;
					queue1[j] = next1;
					queue2[j] = next2;
					step[j++] = s;
				}
			}
			if(map[t2][t1])
			{
				next1 = min(t1, map[t2][t1]);
				next2 = max(t1, map[t2][t1]);
				if(!chk[next1][next2])
				{
					if(next1 == target || next2 == target)
					{
						break;
					}
					chk[next1][next2] = 1;
					queue1[j] = next1;
					queue2[j] = next2;
					step[j++] = s;
				}
			}
		}
		if(i == j)
		{
			printf("Game #%d\nDestination is Not Reachable !\n\n", ++cas);
		}
		else
		{
			printf("Game #%d\nMinimum Number of Moves = %d\n\n", ++cas, s);
		}
	}
	return 0;
}

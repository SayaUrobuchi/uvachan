/*
ID: sa072682
LANG: C
TASK: packrec
*/
#include <stdio.h>
#include <stdlib.h>

int ary[4][2], list[4], anslist[10000], ans, num;
char chk[4];

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

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

void dfs(int depth)
{
	int i, temp, x, y;
	if(depth == 4)
	{
		x = ary[list[0]][0] + ary[list[1]][0] + ary[list[2]][0] + ary[list[3]][0];
		y = max(ary[list[0]][1], max(ary[list[1]][1], max(ary[list[2]][1], ary[list[3]][1])));
		if(x * y < ans)
		{
			/*printf("1 %d\n", x * y);*/
			ans = x * y;
			num = 1;
			anslist[0] = min(x, y);
		}
		else if(x * y == ans)
		{
			anslist[num++] = min(x, y);
		}
		x = max(ary[list[0]][0], max(ary[list[1]][0], ary[list[2]][0])) + ary[list[3]][0];
		y = max(ary[list[0]][1]+ary[list[1]][1]+ary[list[2]][1], ary[list[3]][1]);
		if(x * y < ans)
		{
			/*printf("2 %d\n", x * y);*/
			ans = x * y;
			num = 1;
			anslist[0] = min(x, y);
		}
		else if(x * y == ans)
		{
			anslist[num++] = min(x, y);
		}
		x = max(ary[list[0]][0]+ary[list[1]][0], ary[list[2]][0]) + ary[list[3]][0];
		y = max(max(ary[list[0]][1], ary[list[1]][1])+ary[list[2]][1], ary[list[3]][1]);
		if(x * y < ans)
		{
			/*printf("3 %d\n", x * y);*/
			ans = x * y;
			num = 1;
			anslist[0] = min(x, y);
		}
		else if(x * y == ans)
		{
			anslist[num++] = min(x, y);
		}
		x = ary[list[0]][0] + max(ary[list[1]][0], ary[list[2]][0]) + ary[list[3]][0];
		y = max(ary[list[0]][1], max(ary[list[1]][1]+ary[list[2]][1], ary[list[3]][1]));
		if(x * y < ans)
		{
			/*printf("4 %d\n", x * y);*/
			ans = x * y;
			num = 1;
			anslist[0] = min(x, y);
		}
		else if(x * y == ans)
		{
			anslist[num++] = min(x, y);
		}
		x = max(ary[list[0]][0], ary[list[1]][0]) + ary[list[2]][0] + ary[list[3]][0];
		y = max(ary[list[0]][1]+ary[list[1]][1], max(ary[list[2]][1], ary[list[3]][1]));
		if(x * y < ans)
		{
			/*printf("5 %d\n", x * y);*/
			ans = x * y;
			num = 1;
			anslist[0] = min(x, y);
		}
		else if(x * y == ans)
		{
			anslist[num++] = min(x, y);
		}
		if(ary[list[3]][0] >= ary[list[1]][0] && ary[list[2]][1] >= ary[list[3]][1])
		{
			x = max(ary[list[0]][0]+ary[list[1]][0], ary[list[2]][0]+ary[list[3]][0]);
			y = max(ary[list[0]][1]+ary[list[2]][1], ary[list[1]][1]+ary[list[3]][1]);
			if(x * y < ans)
			{
				/*printf("6 %d\n", x * y);
				for(i=0; i<4; i++) printf("XDD %d %d %d\n", i, ary[list[i]][0], ary[list[i]][1]);*/
				ans = x * y;
				num = 1;
				anslist[0] = min(x, y);
			}
			else if(x * y == ans)
			{
				anslist[num++] = min(x, y);
			}
		}
		return;
	}
	for(i=0; i<4; i++)
	{
		if(chk[i])
		{
			chk[i] = 0;
			list[depth] = i;
			dfs(depth+1);
			temp = ary[i][0];
			ary[i][0] = ary[i][1];
			ary[i][1] = temp;
			dfs(depth+1);
			temp = ary[i][0];
			ary[i][0] = ary[i][1];
			ary[i][1] = temp;
			chk[i] = 1;
		}
	}
}

int main()
{
	int i;
	freopen("packrec.in", "r", stdin);
	freopen("packrec.out", "w", stdout);
	for(i=0; i<4; i++)
	{
		scanf("%d%d", &ary[i][0], &ary[i][1]);
		chk[i] = 1;
	}
	ans = 100000;
	dfs(0);
	printf("%d\n", ans);
	qsort(anslist, num, sizeof(int), comp);
	printf("%d %d\n", anslist[0], ans/anslist[0]);
	for(i=1; i<num; i++)
	{
		if(anslist[i] != anslist[i-1])
		{
			printf("%d %d\n", anslist[i], ans/anslist[i]);
		}
	}
	scanf(" ");
	return 0;
}

/*
	ID: sa072682
	LANG: C
	TASK: milk3
*/
#include <stdio.h>
#include <string.h>

char chk[21][21][21], queue[10000][3], tbl[21];

int main()
{
	int a, b, c, i, j, ta, tb, tc;
	freopen("milk3.in", "r", stdin);
	freopen("milk3.out", "w", stdout);
	scanf("%d%d%d", &a, &b, &c);
	memset(chk, 1, sizeof(chk));
	chk[0][0][c] = 0;
	queue[0][0] = queue[0][1] = 0;
	queue[0][2] = c;
	tbl[c] = 1;
	for(i=0, j=1; i<j; i++)
	{
		ta = queue[i][0];
		tb = queue[i][1];
		tc = queue[i][2];
		if(ta > b - tb)
		{
			if(chk[ta-b+tb][b][tc])
			{
				chk[ta-b+tb][b][tc] = 0;
				queue[j][0] = ta - b + tb;
				queue[j][1] = b;
				queue[j++][2] = tc;
			}
		}
		else
		{
			if(chk[0][tb+ta][tc])
			{
				chk[0][tb+ta][tc] = 0;
				queue[j][0] = 0;
				queue[j][1] = tb + ta;
				queue[j++][2] = tc;
				tbl[tc] = 1;
			}
		}
		if(ta > c - tc)
		{
			if(chk[ta-c+tc][tb][c])
			{
				chk[ta-c+tc][tb][c] = 0;
				queue[j][0] = ta - c + tc;
				queue[j][1] = tb;
				queue[j++][2] = c;
			}
		}
		else
		{
			if(chk[0][tb][tc+ta])
			{
				chk[0][tb][tc+ta] = 0;
				queue[j][0] = 0;
				queue[j][1] = tb;
				queue[j++][2] = tc + ta;
				tbl[tc+ta] = 1;
			}
		}
		if(tb > a - ta)
		{
			if(chk[a][tb-a+ta][tc])
			{
				chk[a][tb-a+ta][tc] = 0;
				queue[j][0] = a;
				queue[j][1] = tb - a + ta;
				queue[j++][2] = tc;
			}
		}
		else
		{
			if(chk[ta+tb][0][tc])
			{
				chk[ta+tb][0][tc] = 0;
				queue[j][0] = ta + tb;
				queue[j][1] = 0;
				queue[j++][2] = tc;
			}
		}
		if(tb > c - tc)
		{
			if(chk[ta][tb-c+tc][c])
			{
				chk[ta][tb-c+tc][c] = 0;
				queue[j][0] = ta;
				queue[j][1] = tb - c + tc;
				queue[j++][2] = c;
			}
		}
		else
		{
			if(chk[ta][0][tc+tb])
			{
				chk[ta][0][tc+tb] = 0;
				queue[j][0] = ta;
				queue[j][1] = 0;
				queue[j++][2] = tc + tb;
				if(!ta)
				{
					tbl[tc+tb] = 1;
				}
			}
		}
		if(tc > a - ta)
		{
			if(chk[a][tb][tc-a+ta])
			{
				chk[a][tb][tc-a+ta] = 0;
				queue[j][0] = a;
				queue[j][1] = tb;
				queue[j++][2] = tc - a + ta;
			}
		}
		else
		{
			if(chk[ta+tc][tb][0])
			{
				chk[ta+tc][tb][0] = 0;
				queue[j][0] = ta + tc;
				queue[j][1] = tb;
				queue[j++][2] = 0;
			}
		}
		if(tc > b - tb)
		{
			if(chk[ta][b][tc-b+tb])
			{
				chk[ta][b][tc-b+tb] = 0;
				queue[j][0] = ta;
				queue[j][1] = b;
				queue[j++][2] = tc - b + tb;
				if(!ta)
				{
					tbl[tc-b+tb] = 1;
				}
			}
		}
		else
		{
			if(chk[ta][tb+tc][0])
			{
				chk[ta][tb+tc][0] = 0;
				queue[j][0] = ta;
				queue[j][1] = tb + tc;
				queue[j++][2] = 0;
				if(!ta)
				{
					tbl[0] = 1;
				}
			}
		}
	}
	for(i=0, j=0; i<21; i++)
	{
		if(tbl[i])
		{
			if(j)
			{
				printf(" %d", i);
			}
			else
			{
				printf("%d", i);
				j = 1;
			}
		}
	}
	printf("\n");
	scanf(" ");
	return 0;
}

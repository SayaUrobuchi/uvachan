#include <stdio.h>
#include <string.h>

int ary[9][9], listx[81], listy[81], c[9][10], r[9][10], a[3][3][10], count, n;

void recursion(int now)
{
	int i, j, x, y;
	if(now == n)
	{
		for(i=0; i<9; i++)
		{
			printf("%d", ary[i][0]);
			for(j=1; j<9; j++)
			{
				printf(" %d", ary[i][j]);
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	x = listx[now];
	y = listy[now];
	for(i=1; i<10; i++)
	{
		if(!c[x][i] && !r[y][i] && !a[x/3][y/3][i])
		{
			ary[x][y] = i;
			c[x][i] = r[y][i] = a[x/3][y/3][i] = 1;
			recursion(now+1);
			c[x][i] = r[y][i] = a[x/3][y/3][i] = 0;
		}
	}
}

int main()
{
	int i, j;
	while(scanf("%d", &ary[0][0]) == 1)
	{
		n = count = 0;
		memset(c, 0, sizeof(c));
		memset(r, 0, sizeof(r));
		memset(a, 0, sizeof(a));
		if(!ary[0][0])
		{
			listx[n] = 0;
			listy[n++] = 0;
		}
		c[0][ary[0][0]] = r[0][ary[0][0]] = a[0][0][ary[0][0]] = 1;
		for(i=0; i<9; i++)
		{
			for(j=0; j<9; j++)
			{
				if(i || j)
				{
					scanf("%d", &ary[i][j]);
					if(!ary[i][j])
					{
						listx[n] = i;
						listy[n++] = j;
					}
					c[i][ary[i][j]] = r[j][ary[i][j]] = a[i/3][j/3][ary[i][j]] = 1;
				}
			}
		}
		recursion(0);
		printf("there are a total of %d solution(s).\n", count);
	}
	return 0;
}

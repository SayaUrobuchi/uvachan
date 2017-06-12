#include <stdio.h>
#include <string.h>

int board[4][4], ans[2][4][4], row[4], column[4], cor, rcor, count, n, m, p;

void dfs(int c, int r, int value)
{
	int i, j, temp, flag, sum;
	/*printf("%d %d\n", c, r);*/
	if(r == 3)
	{
		temp = n - column[c];
		if(temp < 1 || temp > 7)
		{
			/*printf("temp %d\n", temp);*/
			return;
		}
		/*printf("temp %d %d\n", temp, temp<1);*/
		flag = 0;
		row[r] += temp;
		flag |= (row[r] >= n);
		column[c] += temp;
		if(r + c == 3)
		{
			rcor += temp;
			flag |= (rcor > n);
		}
		if(!flag)
		{
			board[c][r] = temp;
			dfs(c+1, 0, (value*temp)%m);
		}
		row[r] -= temp;
		column[c] -= temp;
		if(r == c)
		{
			cor -= temp;
		}
		else if(r + c == 3)
		{
			rcor -= temp;
		}
		return;
	}
	if(c == 3)
	{
		for(i=0, sum=0; i<4; i++)
		{
			temp = n - row[i];
			if(temp < 1 || temp > 7)
			{
				return;
			}
			sum += temp;
			if(temp > n)
			{
				return;
			}
			if(!i)
			{
				if(cor + temp != n)
				{
					return;
				}
			}
			if(i == 3)
			{
				if(rcor + temp != n)
				{
					return;
				}
			}
			value *= temp;
			value %= m;
			board[c][i] = temp;
		}
		if(sum != n)
		{
			return;
		}
		if(value <= p)
		{
			if(count < 2)
			{
				for(i=0; i<4; i++)
				{
					for(j=0; j<4; j++)
					{
						ans[count][i][j] = board[i][j];
					}
				}
			}
			count++;
		}
		return;
	}
	for(i=1; i<=7; i++)
	{
		flag = 0;
		row[r] += i;
		flag |= (row[r] >= n);
		column[c] += i;
		flag |= (column[c] > n);
		if(r == c)
		{
			cor += i;
			flag |= (cor > n);
		}
		else if(r + c == 3)
		{
			rcor += i;
			flag |= (rcor > n);
		}
		if(!flag)
		{
			board[c][r] = i;
			dfs(c, r+1, value*i);
		}
		row[r] -= i;
		column[c] -= i;
		if(r == c)
		{
			cor -= i;
		}
		else if(r + c == 3)
		{
			rcor -= i;
		}
	}
}

int main()
{
	int cas, i, j, k;
	cas = 0;
	while(scanf("%d%d%d", &n, &m, &p) == 3)
	{
		if(!n && !m && !p)
		{
			break;
		}
		memset(row, 0, sizeof(row));
		memset(column, 0, sizeof(column));
		count = cor = rcor = 0;
		dfs(0, 0, 1);
		printf("Set %d:\n%d\n", ++cas, count);
		if(count)
		{
			for(i=0; i<4; i++)
			{
				for(j=0; j<4; j++)
				{
					printf("%d", ans[0][i][j]);
				}
				printf("\n");
			}
			printf("....\n");
			if(count > 1)
			{
				for(i=0; i<4; i++)
				{
					for(j=0; j<4; j++)
					{
						printf("%d", ans[1][i][j]);
					}
					printf("\n");
				}
				printf("....\n");
			}
		}
	}
	return 0;
}

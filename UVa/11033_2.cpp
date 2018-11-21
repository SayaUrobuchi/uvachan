#include <stdio.h>
#include <string.h>

int *ans[2][4], *list[4], path[4], count, repeat, n, m, o, len, *ptr, *p;
int permutation[29][250][4], product[29][250], num[29], tbl[29][2500], dp[4];

void dfs4()
{
	int i, flag, temp, *q;
	for(i=0, temp=0; i<4; i++)
	{
		flag = n - list[0][i] - list[1][i] - list[3][i];
		if(flag > 7 || flag < 1) return;
		temp += (flag-1) * dp[i];
	}
	temp = tbl[n][temp] - 1;
	if(temp==-1) return;
	q = permutation[n][temp];
	if(list[0][0]+list[1][1]+q[2]+list[3][3] != n) return;
	if(list[0][3]+list[1][2]+q[1]+list[3][0] != n) return;
	if((((((product[n][path[0]]*product[n][path[1]])%m)*product[n][temp])%m)*product[n][path[3]]) % m > o) return;
	list[2] = q;
	/*repeat += (path[3] == path[0]);*/
	/*printf("%d %d %d %d\n", path[0], path[1], temp, path[3]);*/
	if(count < 2)
	{
		for(i=0; i<4; i++)
		{
			ans[count][i] = list[i];
		}
	}
	count++;
}

void dfs3()
{
	int i, *q;
	for(i=path[0], q=p; i<len; i++, q+=4)
	{
		list[3] = q;
		path[3] = i;
		dfs4();
	}
}

void dfs2()
{
	int i, *q;
	for(i=0, q=ptr; i<len; i++, q+=4)
	{
		list[1] = q;
		path[1] = i;
		dfs3();
	}
}

void dfs()
{
	int i;
	for(i=0, p=ptr; i<len; i++, p+=4)
	{
		list[0] = p;
		path[0] = i;
		dfs2();
	}
}

void precalc(int depth, int value, int multi, int hash)
{
	int i;
	if(depth == 4)
	{
		if(value == n)
		{
			for(i=0; i<4; i++)
			{
				permutation[n][count][i] = path[i];
			}
			product[n][count] = multi;
			tbl[n][hash] = count + 1;
			count++;
		}
		return;
	}
	for(i=1; i<=7; i++)
	{
		if(value + i <= n)
		{
			path[depth] = i;
			precalc(depth+1, value+i, multi*i, hash+(i-1)*dp[depth]);
		}
		else
		{
			return;
		}
	}
}

int main()
{
	int cas, i, j, k;
	cas = 0;
	dp[0] = 1;
	for(i=1; i<4; i++)
	{
		dp[i] = dp[i-1] * 7;
	}
	for(n=4; n<=28; n++)
	{
		count = 0;
		precalc(0, 0, 1, 0);
		num[n] = count;
	}
	/*n = 16;
	len = num[n];
	ptr = (int*)permutation[n];
	m = 1;
			for(i=0, k=num[n]/2; i<k; i++)
			{
				list[0] = permutation[n][i];
				dfs(1);
			}
			k = count;
			if(num[n] % 2)
			{
				list[0] = permutation[n][i];
				dfs(1);
			}
			count += k;
	printf("%d\n", count);
	return 0;*/
	while(scanf("%d%d%d", &n, &m, &o) == 3)
	{
		if(!n && !m && !o)
		{
			break;
		}
		count = 0;
		if(n >= 4 && n <= 28)
		{
			repeat = 0;
			len = num[n];
			ptr = (int*)permutation[n];
			dfs();
			/*printf("%d %d\n", count, repeat);*/
			if(count == 1 && k >= 1)
			{
				for(i=0; i<4; i++)
				{
					ans[1][i] = ans[0][3-i];
				}
			}
			count += count - repeat;
		}
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

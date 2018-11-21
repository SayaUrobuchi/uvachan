#include <stdio.h>
#include <string.h>

int ary[100005], c[100005], tbl[100005][20], ultimate[100005], loc[100005], dp[18];

int max(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int min(int p, int q)
{
	if(p > q)
	{
		return q;
	}
	return p;
}

int main()
{
	int n, m, i, j, k, p, q, num, last, ans, left, right;
	dp[0] = 1;
	for(i=1; i<18; i++)
	{
		dp[i] = dp[i-1] * 2;
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		scanf("%d", &m);
		ary[0] = 0;
		c[0] = 0;
		for(i=0, num=0, last=-1; i<n; i++)
		{
			scanf("%d", &j);
			j += 100000;
			if(j > last)
			{
				k = i;
				c[num+1] = 1 + c[num];
				last = j;
				loc[k] = ++num;
			}
			else
			{
				c[num]++;
			}
			ary[i] = k;
		}
		c[num+1] = c[num] + 1;
		for(i=num; i; i--)
		{
			tbl[i][0] = c[i] - c[i-1];
			//printf("tbl[%d][0]: Default %d\n", i, tbl[i][0]);
			for(j=0, k=1; i+dp[k]<=num; j++, k++)
			{
				tbl[i][k] = max(tbl[i][j], tbl[i+dp[j]][j]);
				//printf("tbl[%d][%d] = %d from max(%d, %d);\n", i, k, tbl[i][k], tbl[i][j], tbl[i+dp[j]][j]);
			}
			if(i + dp[j] <= num)
			{
				ultimate[i] = max(tbl[i][j], ultimate[i+dp[j]]);
				tbl[i][k] = ultimate[i];
				//printf("Ultimate! %d from max(%d, %d)\n", ultimate[i], tbl[i][j], ultimate[i+dp[j]]);
			}
			else
			{
				ultimate[i] = tbl[i][j];
				tbl[i][k] = ultimate[i];
				//printf("Extra Ultimate!!! %d\n", ultimate[i]);
			}
		}
		while(m--)
		{
			scanf("%d%d", &p, &q);
			if(p == q)
			{
				printf("1\n");
				continue;
			}
			left = loc[ary[p-1]] + 1;
			right = loc[ary[q-1]];
			if(c[right] > q)
			{
				right--;
			}
			ans = 0;
			/*printf("left: %d, c => %d; right: %d, c => %d\n", left, c[left], right, c[right]);
			printf("l: %d, c => %d; r: %d, c => %d\n", left, c[left], right, c[right]);*/
			if(c[left] <= q && c[right] >= p && right >= left)
			{
				if(right == left)
				{
					ans = c[left] - c[left-1];
				}
				else
				{
					k = right - left + 1;
					for(i=0; i<18; i++)
					{
						if(dp[i] >= k)
						{
							ans = max(tbl[left][i-1], tbl[right-dp[i-1]+1][i-1]);
							/*printf("i: %d, dp[i-1]: %d\n", i, dp[i-1]);
							printf("ans from max(%d, %d)\n", tbl[left][i-1], tbl[right-dp[i-1]][i-1]);*/
							/*printf("ans: %d\n", ans);*/
							break;
						}
					}
				}
			}
			left = loc[ary[p-1]] - 1;
			right = loc[ary[q-1]] - 1;
			/*printf("left: %d, right: %d\n", left, right);
			printf("c: l => %d, r => %d\n", c[left], c[right]);*/
			if(left != num)
			{
				ans = max(ans, min(q, c[left+1])-max(p, c[left]+1)+1);
			}
			if(right != num)
			{
				ans = max(ans, min(q, c[right+1])-max(p, c[right]+1)+1);
			}
			printf("%d\n", ans);
		}
	}
	return 0;
}

#include <stdio.h>

int table[21], dp[10], tmp[10];

int main()
{
	int cas, n, m, i, j, k, l, p, in, sum, max, now, num, num2, lim, tmp2;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		sum = 0;
		num = 0;
		while(n--)
		{
			scanf("%d", &m);
			max = 0;
			now = 0;
			lim = 1;
			table[0] = 0;
			for(j=0; j<m; j++)
			{
				scanf("%d", &in);
				now -= in - 10;
				if(now > max)
				{
					max = now;
					lim = 1;
					table[0] = j + 1;
				}
				else if(now == max)
				{
					table[lim++] = j + 1;
				}
			}
			sum += max;
			if(lim > 10)
			{
				lim = 10;
			}
			if(num)
			{
				num2 = 0;
				for(j=0; j<lim; j++)
				{
					for(k=0; k<num; k++)
					{
						tmp2 = table[j] + dp[k];
						for(l=0; l<num2; l++)
						{
							if(tmp[l] >= tmp2)
							{
								break;
							}
						}
						if(l == 10)
						{
							break;
						}
						if(l < num2 && tmp[l] == tmp2)
						{
							continue;
						}
						if(num2 > 9)
						{
							num2--;
						}
						for(p=num2; p>l; p--)
						{
							tmp[p] = tmp[p-1];
						}
						tmp[l] = tmp2;
						num2++;
					}
					if(!k)
					{
						break;
					}
				}
				for(j=0; j<num2; j++)
				{
					dp[j] = tmp[j];
				}
				num = num2;
			}
			else
			{
				for(j=0; j<lim; j++)
				{
					dp[j] = table[j];
				}
				num = j;
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("Workyards %d\nMaximum profit is %d.\nNumber of pruls to buy:", ++cas, sum);
		for(i=0; i<num; i++)
		{
			printf(" %d", dp[i]);
		}
		printf("\n");
	}
	return 0;
}
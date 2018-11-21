#include <stdio.h>
#include <string.h>

int need[20], map[20][20], dis[20], queue[1000000], queue2[1000000];
char chk[20], chk2[1201][1201];

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
	int cas, count, n, m, o, i, j, k, l, p, q, temp, temp2, sum, ans;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=1; i<n; i++)
		{
			scanf("%d", &need[i]);
		}
		memset(map, 0, sizeof(map));
		while(scanf("%d%d%d", &i, &j, &k) == 3)
		{
			if(!(i + j + k))
			{
				break;
			}
			i--;
			j--;
			map[i][j] = map[j][i] = k;
		}
		for(i=1; i<n; i++)
		{
			dis[i] = map[0][i];
			chk[i] = 1;
		}
		for(i=1, sum=0; i<n; i++)
		{
			for(p=1, j=2147483647; p<n; p++)
			{
				if(chk[p] && dis[p] && dis[p] < j)
				{
					j = dis[p];
					k = p;
				}
			}
			chk[k] = 0;
			for(p=1; p<n; p++)
			{
				if(chk[p] && map[k][p] && (dis[k] + map[k][p] < dis[p] || !dis[p]))
				{
					dis[p] = dis[k] + map[k][p];
				}
			}
			dis[k] *= 2;
			sum += need[k] * dis[k];
		}
		if(sum > 3600)
		{
			printf("Test Case #: %d\nToo few trucks\n", ++cas);
		}
		else
		{
			queue[0] = queue2[0] = 0;
			memset(chk2, 1, sizeof(chk2));
			for(i=1, q=1, ans=sum; i<n; i++)
			{
				temp = dis[i];
				for(j=0, m=-1; j<need[i]; j++)
				{
					for(p=o=q-1; p>m; p--)
					{
						k = queue[p] + temp;
						l = queue2[p];
						if(k <= l)
						{
							if(chk2[k][l])
							{
								chk2[k][l] = 0;
								queue[q] = k;
								queue2[q++] = l;
								if(ans > max(k, max(l, sum-k-l)))
								{
									ans = max(k, max(l, sum-k-l));
								}
							}
						}
						k = queue[p];
						l = queue2[p] + temp;
						if(l <= 1200)
						{
							if(chk2[k][l])
							{
								chk2[k][l] = 0;
								queue[q] = k;
								queue2[q++] = l;
								if(ans > max(k, max(l, sum-k-l)))
								{
									ans = max(k, max(l, sum-k-l));
								}
							}
						}
					}
					m = o;
				}
			}
			if(ans > 1200)
			{
                printf("Test Case #: %d\nToo few trucks\n", ++cas);
			}
			else
			{
				printf("Test Case #: %d\n%d mins\n", ++cas, ans);
			}
		}
	}
	return 0;
}

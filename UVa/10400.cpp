#include <stdio.h>
#include <string.h>

int from[100][64001], ary[100];
char sym[100][64001], tab[64001], tmp[64001];

void recursion(int now, int n)
{
	if(!n)
	{
		return;
	}
	recursion(from[n][now], n-1);
	printf("%d%c", ary[n-1], sym[n][now]);
}

int main()
{
	int count, n, i, j, now, next;
	scanf("%d", &count);
	while(count--)
	{
		memset(tab, 0, sizeof(tab));
		memset(tmp, 0, sizeof(tmp));
		scanf("%d%d", &n, &now);
		ary[0] = now;
		tab[now+32000] = 1;
		for(j=1; j<n; j++)
		{
			scanf("%d", &now);
			ary[j] = now;
			for(i=0; i<64001; i++)
			{
				if(tab[i])
				{
					next = i + now;
					if(next < 64001)
					{
						tmp[next] = 1;
						from[j][next] = i;
						sym[j][next] = '+';
					}
					next = i - now;
					if(next > -1)
					{
                        tmp[next] = 1;
						from[j][next] = i;
						sym[j][next] = '-';
					}
					next = i - 32000;
					next *= now;
					next += 32000;
					if(next > -1 && next < 64001)
					{
                        tmp[next] = 1;
						from[j][next] = i;
						sym[j][next] = '*';
					}
					if(now)
					{
						next = i - 32000;
						if(!(next % now))
						{
							next /= now;
							next += 32000;
							if(next > -1 && next < 64001)
							{
		                        tmp[next] = 1;
								from[j][next] = i;
								sym[j][next] = '/';
							}
						}
					}
				}
			}
			memcpy(tab, tmp, sizeof(tab));
			memset(tmp, 0, sizeof(tmp));
		}
		scanf("%d", &now);
		now += 32000;
		if(tab[now])
		{
			recursion(now, j-1);
			printf("%d=%d\n", ary[n-1], now-32000);
		}
		else
		{
			printf("NO EXPRESSION\n");
		}
	}
	return 0;
}

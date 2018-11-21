#include <stdio.h>
#include <string.h>

int from[100][64001], ary[100], list[64001], tmp[64001];
char sym[100][64001], tab[64001];

void recursion(int now, int n)
{
	if(!n)
	{
		return;
	}
	recursion(from[n][now], n-1);
	printf("%d%c", ary[n-1], sym[n][now]);
}

int search(int n, int lim)
{
	int i;
	for(i=0; i<lim; i++)
	{
		if(tmp[i] == n)
		{
			return i;
		}
	}
}

int main()
{
	int count, n, i, j, n1, n2, now, next;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &now);
		ary[0] = now;
		list[0] = now + 32000;
		n1 = 1;
		for(j=1; j<n; j++)
		{
			scanf("%d", &now);
			ary[j] = now;
			n2 = 0;
			memset(tab, 1, sizeof(tab));
			for(i=0; i<n1; i++)
			{
				next = list[i] + now;
				if(next < 64001)
				{
					if(tab[next])
					{
						tab[next] = 0;
						tmp[n2] = next;
						from[j][n2] = i;
						sym[j][n2++] = '+';
					}
				}
				next = list[i] - now;
				if(next > -1)
				{
                    if(tab[next])
					{
						tab[next] = 0;
						tmp[n2] = next;
						from[j][n2] = i;
						sym[j][n2++] = '-';
					}
				}
				next = list[i] - 32000;
				next *= now;
				next += 32000;
				if(next > -1 && next < 64001)
				{
                    if(tab[next])
					{
						tab[next] = 0;
						tmp[n2] = next;
						from[j][n2] = i;
						sym[j][n2++] = '*';
					}
				}
				if(now)
				{
					next = list[i] - 32000;
					if(!(next % now))
					{
						next /= now;
						next += 32000;
						if(next > -1 && next < 64001)
						{
	                        if(tab[next])
							{
								tab[next] = 0;
								tmp[n2] = next;
								from[j][n2] = i;
								sym[j][n2++] = '/';
							}
						}
					}
				}
			}
			memcpy(list, tmp, 4 * n2);
			n1 = n2;
		}
		scanf("%d", &now);
		now += 32000;
		if(tab[now])
		{
			printf("NO EXPRESSION\n");
		}
		else
		{
			i = search(now, n2);
			recursion(i, j-1);
			printf("%d=%d\n", ary[n-1], now-32000);
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int tbl[128], htbl[128], used[128];
long long c[16][16];
char str[1000000];

int main()
{
	int count, i, j, cnt, remain, cat, st;
	long long res, sum, m;
	char *ptr;
	c[0][0] = 1;
	for(i=1; i<15; i++)
	{
		c[i][0] = 1;
		for(j=1; j<15; j++)
		{
			c[i][j] = c[i-1][j] + c[i-1][j-1];
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%lld", str, &m);
		m--;
		memset(htbl, -1, sizeof(htbl));
		memset(tbl, -1, sizeof(tbl));
		for(ptr=str, cnt=0; *ptr; ptr++)
		{
			if(tbl[*ptr] == -1)
			{
				cnt++;
				tbl[*ptr] = ptr-str;
			}
		}
		memset(used, 0, sizeof(used));
		remain = 9;
		cat = cnt;
		for(ptr=str; *ptr; ptr++)
		{
			if(tbl[*ptr] == ptr-str)
			{
				cnt--;
			}
			if(htbl[*ptr] == -1)
			{
				cat--;
				for(i=2, res=c[remain][cat]; i<=cat; i++)
				{
					res *= i;
				}
				st = 0;
				for(sum=res; sum<=m&&st<remain; sum+=res, st++);
				m -= sum;
				if(m < 0)
				{
					m += res;
				}
				//printf("**%I64d %I64d %d %d**\n", res, sum, remain, st);
				for(i=(ptr==str?1:0); i<10; i++)
				{
					if(used[i] == 0)
					{
						if(st == 0)
						{
							used[i] = 1;
							htbl[*ptr] = i + '0';
							remain--;
							break;
						}
						st--;
					}
				}
			}
			printf("%c", htbl[*ptr]);
		}
		printf("\n");
	}
	return 0;
}

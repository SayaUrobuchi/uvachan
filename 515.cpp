#include <stdio.h>
#include <string.h>

int max[105], min[105];
int map[105][105];
char buf[1005];

int main()
{
	int n, m, i, j, p, q, r;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(max, 128, sizeof(max));
		memset(min, 1, sizeof(min));
		scanf("%d", &m);
		for(i=0, j=0; i<m; i++)
		{
			scanf("%d%d%s%d", &p, &q, buf, &r);
			if(!strcmp(buf, "gt"))
			{
				if(!q)
				{
					if(r+1 > max[p])
					{
						max[p] = r + 1;
					}
				}
				else
				{
					map[p+q][p] = -r - 1;
				}
			}
			else
			{
				if(!q)
				{
					if(r-1 < min[p])
					{
						min[p] = r - 1;
					}
				}
				else
				{
					map[p][p+q] = r - 1;
				}
			}
		}
		m = j;
		for(i=1; i<=n; i++)
		{
			if(max[p] > min[p])
			{
				break;
			}
		}
		for(k=1; k<=n; k++)
		{
			for(i=1; i<=n; i++)
			{
			}
		}
		if(i > n)
		{
			printf("lamentable kingdom\n");
		}
		else
		{
			printf("successful conspiracy\n");
		}
	}
	return 0;
}

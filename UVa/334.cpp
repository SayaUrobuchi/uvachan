#include <stdio.h>
#include <string.h>

int num;
int map[1000][1000], ary[2][2];
char name[1000][6];
char buf[2008], buf2[2008];

int search(char *s)
{
	int i;
	for(i=0; i<num; i++)
	{
		if(!strcmp(s, name[i]))
		{
			return i;
		}
	}
	strcpy(name[num++], s);
	return i;
}

int main()
{
	int cas, n, m, i, j, k, c, now, last;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		num = 0;
		memset(map, 0, sizeof(map));
		for(i=0; i<n; i++)
		{
			scanf("%d", &m);
			for(j=0; j<m; j++)
			{
				scanf("%s", buf);
				now = search(buf);
				if(j)
				{
					map[last][now] = 1;
				}
				last = now;
			}
		}
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%s", buf, buf2);
			last = search(buf);
			now = search(buf2);
			map[last][now] = 1;
		}
		for(k=0; k<num; k++)
		{
			for(i=0; i<num; i++)
			{
				if(map[i][k])
				{
					for(j=0; j<num; j++)
					{
						if(map[k][j])
						{
							map[i][j] = 1;
						}
					}
				}
			}
		}
		for(i=0, c=0; i<num; i++)
		{
			for(j=i+1; j<num; j++)
			{
				if(!map[i][j] && !map[j][i])
				{
					if(c < 2)
					{
						ary[c][0] = i;
						ary[c][1] = j;
					}
					c++;
				}
			}
		}
		if(!c)
		{
			printf("Case %d, no concurrent events.\n", ++cas);
		}
		else if(c == 1)
		{
			printf("Case %d, 1 concurrent events:\n", ++cas);
			printf("(%s,%s) \n", name[ary[0][0]], name[ary[0][1]]);
		}
		else
		{
			printf("Case %d, %d concurrent events:\n", ++cas, c);
			printf("(%s,%s) (%s,%s) \n", name[ary[0][0]], name[ary[0][1]], name[ary[1][0]], name[ary[1][1]]);
		}
	}
	return 0;
}

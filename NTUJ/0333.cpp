#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int num[1000], con[1000][1000], used[1000];
char name[1000][1000], *p[1000], s1[1000], s2[1000];
double dis[1000], map[1000][1000];

int comp(const void *p, const void *q)
{
	return strcmp(*(char**)p, *(char**)q);
}

int bisearch(char *target, int left, int right)
{
	int center, cmp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center >>= 1;
	if(!(cmp=strcmp(target, p[center])))
	{
		return center;
	}
	else if(cmp > 0)
	{
		return bisearch(target, center+1, right);
	}
	return bisearch(target, left, center-1);
}

int main()
{
	int count, n, m, i, n1, n2, temp;
	double wire, d, now, max;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%lf", &wire);
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", name[i]);
			p[i] = name[i];
			dis[i] = 1e30;
		}
		qsort(p, n, sizeof(char*), comp);
		memset(num, 0, sizeof(num));
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%s%lf", s1, s2, &d);
			n1 = bisearch(s1, 0, n-1);
			n2 = bisearch(s2, 0, n-1);
			con[n1][num[n1]] = n2;
			map[n1][num[n1]++] = d;
			con[n2][num[n2]] = n1;
			map[n2][num[n2]++] = d;
		}
		memset(used, 0, sizeof(used));
		dis[0] = 0;
		for(m=0, now=0.0; m<n; m++)
		{
			for(i=0, max=1e31; i<n; i++)
			{
				if(used[i] == 0 && dis[i] < max)
				{
					max = dis[i];
					temp = i;
				}
			}
			used[temp] = 1;
			now += dis[temp];
			for(i=0; i<num[temp]; i++)
			{
				if(used[con[temp][i]] == 0 && dis[con[temp][i]] > map[temp][i])
				{
					dis[con[temp][i]] = map[temp][i];
				}
			}
		}
		if(now <= wire)
		{
			printf("Need %.1lf miles of cable\n", now);
		}
		else
		{
			printf("Not enough cable\n");
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int map[100][100], num[100], c;
char ary[100][31], s1[31], s2[31], chk[100], used[100];

int comp(const void *p, const void *q)
{
	return strcmp((char*)p, (char*)q);
}

int ssearch(char* now, int left, int right)
{
	int center, cmp;
	center = left + right;
	center /= 2;
	cmp = strcmp(now, ary[center]);
	if(!cmp)
	{
		return center;
	}
	else if(cmp > 0)
	{
		return ssearch(now, center+1, right);
	}
	return ssearch(now, left, center-1);
}

void dfs(int now)
{
	int i;
	for(i=0; i<num[now]; i++)
	{
		if(used[map[now][i]])
		{
			used[map[now][i]] = 0;
			c--;
			dfs(map[now][i]);
		}
	}
}

int main()
{
	int cas, n, m, i, j, ans;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", &ary[i]);
		}
		qsort(ary, n, sizeof(ary[0]), comp);
		memset(num, 0, sizeof(num));
		scanf("%d", &m);
		while(m--)
		{
			scanf("%s%s", s1, s2);
			i = ssearch(s1, 0, n-1);
			j = ssearch(s2, 0, n-1);
			map[i][num[i]++] = j;
			map[j][num[j]++] = i;
		}
		memset(chk, 0, sizeof(chk));
		for(i=0, ans=0; i<n; i++)
		{
			if(num[i] > 1)
			{
				memset(used, 1, sizeof(used));
				used[i] = 0;
				c = 0;
				dfs(i);
				c = -c;
				memset(used, 1, sizeof(used));
				used[i] = 0;
				dfs(map[i][0]);
				if(c)
				{
					chk[i] = 1;
					ans++;
				}
			}
		}
		if(cas)
		{
			printf("\n");
		}
		printf("City map #%d: %d camera(s) found\n", ++cas, ans);
		for(i=0; i<n; i++)
		{
			if(chk[i])
			{
				printf("%s\n", ary[i]);
			}
		}
	}
	return 0;
}

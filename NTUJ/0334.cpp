#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int n, m, ans, used, pre[20], semtype[20], tbl[128];
char name[20][105], *p[20], s[105], s2[105];

int comp(const void *p, const void *q)
{
	return strcmp(*(char**)p, *(char**)q);
}

int dfs(int);

int combi(int depth, int loc, int len, int* list, int* temp, int seme)
{
	int i;
	if(depth == m || depth == len)
	{
		for(i=0; i<depth; i++)
		{
			used |= (1 << temp[i]);
		}
		dfs(seme+1);
		for(i=0; i<depth; i++)
		{
			used -= (1 << temp[i]);
		}
		return 0;
	}
	for(i=loc; i<len; i++)
	{
		temp[depth] = list[i];
		combi(depth+1, i+1, len, list, temp, seme);
	}
	return 0;
}

int valid(int loc, int sem)
{
	return !(used & (1<<loc)) && (used & pre[loc]) == pre[loc] && (semtype[loc] == 'B' || semtype[loc] == tbl[sem]);
}

int dfs(int seme)
{
	int list[20], temp[20], type, i, l, end;
	if(seme >= ans)
	{
		return 0;
	}
	type = seme % 2;
	for(i=0, l=0, end=1; i<n; i++)
	{
		if(valid(i, type))
		{
			list[l++] = i;
		}
		if(!(used & (1<<i)))
		{
			end = 0;
		}
	}
	if(end)
	{
		ans = seme;
		return 0;
	}
	else
	{
		return combi(0, 0, l, list, temp, seme);
	}
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
	if((cmp=strcmp(target, p[center])) == 0)
	{
		return center;
	}
	else if(cmp > 0)
	{
		return bisearch(target, center+1, right);
	}
	else
	{
		return bisearch(target, left, center-1);
	}
}

int main()
{
	int i, temp, now;
	tbl[0] = 'F';
	tbl[1] = 'S';
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == -1 && m == -1)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", name[i]);
			p[i] = name[i];
		}
		qsort(p, n, sizeof(char*), comp);
		for(i=0; i<n; i++)
		{
			scanf("%s%s%d", s, s2, &temp);
			now = bisearch(s, 0, n-1);
			semtype[now] = s2[0];
			pre[now] = 0;
			while(temp--)
			{
				scanf("%s", s2);
				pre[now] += (1 << (bisearch(s2, 0, n-1)));
			}
		}
		ans = 2147483647;
		used = 0;
		dfs(0);
		printf("The minimum number of semesters required to graduate is %d.\n", ans);
	}
	return 0;
}

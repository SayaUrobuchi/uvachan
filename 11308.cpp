#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int iindex[101], rindex[101];
int icost[101], rcost[101];
char iname[101][101], rname[101][101];
char str[1000];
char title[1000];

int icomp(const void *p, const void *q)
{
	return strcmp(iname[*(int*)p], iname[*(int*)q]);
}

int rcomp(const void *p, const void *q)
{
	if(rcost[*(int*)p] == rcost[*(int*)q])
	{
		return strcmp(rname[*(int*)p], rname[*(int*)q]);
	}
	return rcost[*(int*)p] - rcost[*(int*)q];
}

char* caps(char *s)
{
	int i;
	for(i=0; s[i]; i++)
	{
		if(s[i] > 90)
		{
			s[i] -= 32;
		}
	}
	return s;
}

int bisearch(int left, int right)
{
	int center, cmp;
	center = left + right;
	cmp = strcmp(iname[iindex[center]], str);
	if(!cmp)
	{
		return iindex[center];
	}
	else if(cmp > 0)
	{
		return bisearch(left, center-1);
	}
	return bisearch(center+1, right);
}

int main()
{
	int count, n, m, o, b, i, need, temp;
	scanf("%d", &count);
	gets(str);
	while(count--)
	{
		gets(title);
		scanf("%d%d%d", &n, &m, &b);
		for(i=0; i<n; i++)
		{
			scanf("%s%d", iname[i], &icost[i]);
			iindex[i] = i;
		}
		qsort(iindex, n, sizeof(int), icomp);
		gets(str);
		for(i=0; i<m; i++)
		{
			rcost[i] = 0;
			gets(rname[i]);
			scanf("%d", &o);
			while(o--)
			{
				scanf("%s%d", str, &need);
				temp = bisearch(0, n-1);
				rcost[i] += icost[temp] * need;
			}
			rindex[i] = i;
			gets(str);
		}
		qsort(rindex, m, sizeof(int), rcomp);
		printf("%s\n", caps(title));
		for(i=0, temp=1; i<m; i++)
		{
			if(rcost[rindex[i]] <= b)
			{
				printf("%s\n", rname[rindex[i]]);
				temp = 0;
			}
		}
		if(temp)
		{
			printf("Too expensive!\n");
		}
		printf("\n");
	}
	return 0;
}

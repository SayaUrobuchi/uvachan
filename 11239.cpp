#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char project[100][101], student[10000][101], chk[10000], set[10000];
int st[10000], num[100], ptr[100], parent[10000];

int comp(const void *p, const void *q)
{
	int cmp;
	cmp = strcmp(student[*(int*)p], student[*(int*)q]);
	if(cmp)
	{
		return cmp;
	}
	else
	{
		return set[*(int*)p] - set[*(int*)q];
	}
}

int comp2(const void *p, const void *q)
{
	int cmp;
	cmp = num[*(int*)q] - num[*(int*)p];
	if(cmp)
	{
		return cmp;
	}
	else
	{
		return strcmp(project[*(int*)p], project[*(int*)q]);
	}
}

int main()
{
	int n, m, i, j, p, q;
	char buf[101];
	n = 0;
	m = -1;
	while(gets(buf))
	{
		if(buf[0] == 48)
		{
			break;
		}
		else if(buf[0] == 49)
		{
			qsort(st, n, sizeof(int), comp);
			parent[st[0]] = j = st[0];
			for(i=1; i<n; i++)
			{
				p = st[i];
				q = st[i-1];
				if(!strcmp(student[p], student[q]))
				{
					parent[p] = j;
					if(set[p] != set[q])
					{
						chk[parent[p]] = 0;
					}
				}
				else
				{
					parent[p] = j = p;
				}
			}
			for(i=0; i<n; i++)
			{
				if(chk[parent[i]])
				{
					num[set[i]]++;
					chk[parent[i]] = 0;
				}
			}
			qsort(ptr, ++m, sizeof(int), comp2);
			for(i=0; i<m; i++)
			{
				printf("%s %d\n", project[ptr[i]], num[ptr[i]]);
			}
			n = 0;
			m = -1;
		}
		else
		{
			if(buf[0] > 90)
			{
				strcpy(student[n], buf);
				st[n] = n;
				set[n] = m;
				chk[n++] = 1;
			}
			else
			{
				strcpy(project[++m], buf);
				ptr[m] = m;
				num[m] = 0;
			}
		}
	}
	return 0;
}

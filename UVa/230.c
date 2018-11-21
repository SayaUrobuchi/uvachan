#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 2000

int n, m, ai[N], ti[N], list[N], borrowed[N];
char buf[2008];

struct data
{
	char title[90], author[90];
};

struct data book[N];

int acomp(const void *p, const void *q)
{
	int cmp;
	cmp = strcmp(book[*(int*)p].author, book[*(int*)q].author);
	if(cmp != 0)
	{
		return cmp;
	}
	return strcmp(book[*(int*)p].title, book[*(int*)q].title);
}

int tcomp(const void *p, const void *q)
{
	return strcmp(book[ai[*(int*)p]].title, book[ai[*(int*)q]].title);
}

int comp(const void *p, const void *q)
{
	return *(int*)p - *(int*)q;
}

int bisearch(char *s, int left, int right)
{
	int center, cmp;
	center = left + right;
	center >>= 1;
	cmp = strcmp(book[ai[ti[center]]].title, s);
	if(!cmp)
	{
		return ti[center];
	}
	else if(cmp > 0)
	{
		return bisearch(s, left, center-1);
	}
	return bisearch(s, center+1, right);
}

int main()
{
	int i, j, temp;
	char *ptr;
	n = 0;
	while(gets(buf))
	{
		if(!strcmp(buf, "END"))
		{
			break;
		}
		ptr = strtok(buf, "\"");
		strcpy(book[n].title, ptr);
		for(; *ptr; ptr++);
		ptr = strstr(ptr+1, "by");
		strcpy(book[n].author, ptr+3);
		ai[n] = n;
		ti[n] = n;
		n++;
	}
	qsort(ai, n, sizeof(int), acomp);
	qsort(ti, n, sizeof(int), tcomp);
	m = 0;
	while(gets(buf))
	{
		if(!strcmp(buf, "END"))
		{
			break;
		}
		if(!strcmp(buf, "SHELVE"))
		{
			qsort(list, m, sizeof(int), comp);
			for(i=0; i<m; i++)
			{
				for(j=list[i]-1, temp=-1; j>=0; j--)
				{
					if(!borrowed[j])
					{
						temp = j;
						break;
					}
				}
				if(temp == -1)
				{
					printf("Put \"%s\" first\n", book[ai[list[i]]].title);
				}
				else
				{
					printf("Put \"%s\" after \"%s\"\n", book[ai[list[i]]].title, book[ai[temp]].title);
				}
				borrowed[list[i]] = 0;
			}
			printf("END\n");
			m = 0;
		}
		else
		{
			ptr = strtok(buf, "\"");
			ptr = strtok(NULL, "\"");
			temp = bisearch(ptr, 0, n-1);
			if(buf[0] == 'B')
			{
				borrowed[temp] = 1;
			}
			else
			{
				list[m++] = temp;
			}
		}
	}
	return 0;
}

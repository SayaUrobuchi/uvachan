#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[105];
int tbl[128];
char dic[105][25];
char buf[2008], str[2008];
char final[2008];

int comp(const void *p, const void *q)
{
	return strcmp(dic[*(int*)p], dic[*(int*)q]);
}

int bisearch(int left, int right, char *s)
{
	int center, cmp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	cmp = strcmp(dic[index[center]], s);
	if(!cmp)
	{
		return index[center];
	}
	else if(cmp > 0)
	{
		return bisearch(left, center-1, s);
	}
	return bisearch(center+1, right, s);
}

void print(char *s)
{
	int i, j, len;
	for(i=0, len=strlen(s); i+61<len; i=j+1)
	{
		for(j=i+61; s[j]!=' '&&j>i; j--);
		s[j] = 0;
		puts(s+i);
	}
	for(j=len-1; s[j]==' '&&j>i; j--);
	s[j+1] = 0;
	puts(s+i);
}

int main()
{
	int n, i, k, max, now;
	char *ptr;
	for(i='A'; i<'Z'; i++)
	{
		tbl[i] = i + 1;
	}
	tbl[' '] = 'A';
	tbl['Z'] = ' ';
	n = 0;
	while(gets(dic[n]))
	{
		if(!strcmp(dic[n], "#"))
		{
			break;
		}
		index[n] = n;
		n++;
	}
	qsort(index, n, sizeof(int), comp);
	while(gets(buf))
	{
		for(k=0, max=-1; k<28; k++)
		{
			for(i=0; buf[i]; i++)
			{
				buf[i] = tbl[buf[i]];
			}
			strcpy(str, buf);
			now = (bisearch(0, n-1, strtok(str, " ")) != -1);
			while(ptr=strtok(NULL, " "))
			{
				now += (bisearch(0, n-1, ptr) != -1);
			}
			if(now > max)
			{
				strcpy(final, buf);
				max = now;
			}
		}
		print(final);
	}
	return 0;
}

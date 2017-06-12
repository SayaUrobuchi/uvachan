#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define TIMES 50
#define FLEN 50
#define FNUM 50

char pre[TIMES*6+1];

int fcomp(const void *p, const void *q)
{
	return strcmp((char*)p, (char*)q);
}

void recursion(char *s, int csize)
{
	int i, f;
	char buf[FLEN];
	char fary[FNUM][FLEN];
	f = 0;
	if(csize)
	{
		printf("%.*s%s\n", csize, pre, s);
	}
	else
	{
		printf("ROOT\n");
		if(s[0] == 'd')
		{
			recursion(s, csize+6);
		}
		else if(s[0] == 'f')
		{
			strcpy(fary[f++], s);
		}
	}
	while(gets(buf))
	{
		if(buf[0] == 'd')
		{
			recursion(buf, csize+6);
		}
		else if(buf[0] == 'f')
		{
			strcpy(fary[f++], buf);
		}
		else
		{
			break;
		}
	}
	if(f)
	{
		qsort(fary, f, sizeof(fary[0]), fcomp);
		for(i=0; i<f; i++)
		{
			printf("%.*s%s\n", csize, pre, fary[i]);
		}
	}
}

int main()
{
	int cas, i;
	char buf[FLEN];
	char *ptr;
	cas = 0;
	ptr = pre;
	for(i=0; i<TIMES; i++, ptr+=6)
	{
		strcpy(ptr, "|     ");
	}
	strcpy(buf, "ROOT");
	while(gets(buf))
	{
		if(buf[0] == '#')
		{
			break;
		}
		if(cas)
		{
			printf("\n");
		}
		printf("DATA SET %d:\n", ++cas);
		recursion(buf, 0);
	}
	return 0;
}

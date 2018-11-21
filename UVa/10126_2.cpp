#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *ary[10005], str[10005][205], sp[130], buf[1000005];

int comp(const void *p, const void *q)
{
	return strcmp(*(char**)p, *(char**)q);
}

char *trans(char *p)
{
	char *q;
	for(q=p; *q; q++)
	{
		if(*q < 97)
		{
			*q += 32;
		}
	}
	return p;
}

int main()
{
	int cas, n, m, i, last, ans;
	char *ptr;
	cas = 0;
	for(i=1, ptr=sp; i<128; i++)
	{
		if(i < 65 || (i > 90 && i < 97) || i > 122)
		{
			*(ptr++) = i;
		}
	}
	*ptr = 0;
	while(scanf("%d", &n) == 1)
	{
		if(cas)
		{
			puts("");
		}
		cas = 1;
		m = 0;
		while(gets(buf))
		{
			ptr = strtok(buf, sp);
			if(ptr)
			{
				do
				{
					strcpy(str[m], trans(ptr));
					ary[m] = str[m];
					m++;
					if(strcmp(str[m-1], "endoftext") == 0)
					{
						break;
					}
				}while(ptr=strtok(NULL, sp));
				if(ptr)
				{
					break;
				}
			}
		}
		qsort(ary, m-1, sizeof(char*), comp);
		for(i=1, last=1, ans=0; i<m; i++)
		{
			if(strcmp(ary[i], ary[i-1]) == 0)
			{
				last++;
			}
			else
			{
				if(last == n)
				{
					puts(ary[i-1]);
					ans = 1;
				}
				last = 1;
			}
		}
		if(ans == 0)
		{
			puts("There is no such word.");
		}
	}
	return 0;
}

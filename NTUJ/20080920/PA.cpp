#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int id[10000];
char str[10000], buf[10000], res[10000];

int comp(const void *p, const void *q)
{
	return str[*(int*)p]==str[*(int*)q] ? *(int*)p - *(int*)q : str[*(int*)p] - str[*(int*)q];
}

int main()
{
	int i, j, k, t, bl, len, rflen;
	while(gets(str))
	{
		if(strcmp(str, "THEEND") == 0)
		{
			break;
		}
		gets(buf);
		len = strlen(str);
		bl = strlen(buf);
		rflen = bl / len;
		res[bl] = 0;
		for(i=0; i<len; i++)
		{
			id[i] = i;
		}
		qsort(id, len, sizeof(int), comp);
		for(i=0, j=0; i<len; i++)
		{
			for(k=id[i], t=j+rflen; j<t; j++, k+=len)
			{
				res[k] = buf[j];
			}
		}
		puts(res);
	}
	return 0;
}

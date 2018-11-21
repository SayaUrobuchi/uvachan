#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *a1[5000005], *a2[5000005], *list[2500005], s1[10000005], s2[100000005], sp[128];

int comp(const void *p, const void *q)
{
	return strcmp(*(char**)p, *(char**)q);
}

int isupper(char c)
{
	return c >= 65 && c <= 90;
}

void lower(char *s)
{
	for(; *s; *s=isupper(*s)?*s+32:*s, s++);
}

int bisearch(char *s, int left, int right)
{
	int center, cmp;
	if(left > right)
	{
		return -1;
	}
	center = ((left+right)>>1);
	if((cmp=strcmp(s, a2[center])) == 0)
	{
		return center;
	}
	else if(cmp > 0)
	{
		return bisearch(s, center+1, right);
	}
	return bisearch(s, left, center-1);
}

int main()
{
	int cas, i, j, l1, l2, temp;
	char *ptr;
	cas = 0;
	for(i=32, ptr=sp; i<128; i++)
	{
		if(isupper(i) == 0 && (i >= 97 && i <= 122) == 0)
		{
			*(ptr++) = i;
		}
	}
	*ptr = 0;
	while(gets(s1))
	{
		gets(s2);
		lower(s1), lower(s2);
		a1[0] = strtok(s1, sp);
		for(i=1; a1[i]=strtok(NULL, sp); i++);
		a2[0] = strtok(s2, sp);
		for(j=1; a2[j]=strtok(NULL, sp); j++);
		qsort(a1, l1=i, sizeof(char*), comp), qsort(a2, l2=j, sizeof(char*), comp);
		for(i=0, j=0; i<l1; i++)
		{
			if(i == 0 || strcmp(a1[i], a1[i-1]))
			{
				if(i+1 < l1 && strcmp(a1[i], a1[i+1]) == 0)
				{
					temp = bisearch(a1[i], 0, l2-1);
					if(temp != -1)
					{
						if((temp-1 >= 0 && strcmp(a2[temp], a2[temp-1]) == 0) || 
						   (temp+1 < l2 && strcmp(a2[temp], a2[temp+1]) == 0))
						{
							list[j++] = a1[i];
						}
					}
				}
			}
		}
		if(cas++)
		{
			printf("\n");
		}
		if(j == 0)
		{
			printf("<NONE>\n");
		}
		else
		{
			for(i=0; i<j; i++)
			{
				puts(list[i]);
			}
		}
	}
	return 0;
}

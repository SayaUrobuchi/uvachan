#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[3000];
char ary[3000][11];

int comp(const void *p, const void *q)
{
	return strcmp(ary[*(int*)p], ary[*(int*)q]);
}

int stringcmp(char* s1, char* s2)
{
	int i;
	for(i=0; s1[i]&&s2[i]; i++)
	{
		if(s1[i] != s2[i])
		{
			return 1;
		}
	}
	return 0;
}

int main()
{
	int cas, n, i;
	n = cas = 0;
	while(gets(ary[n]))
	{
		if(ary[n][0] == '9')
		{
			qsort(index, n, sizeof(int), comp);
			for(i=1; i<n; i++)
			{
				if(!stringcmp(ary[index[i-1]], ary[index[i]]))
				{
					break;
				}
			}
			if(i == n)
			{
				printf("Set %d is immediately decodable\n", ++cas);
			}
			else
			{
				printf("Set %d is not immediately decodable\n", ++cas);
			}
			n = 0;
		}
		else
		{
			index[n] = n;
			n++;
		}
	}
	return 0;
}

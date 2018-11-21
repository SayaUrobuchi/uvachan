#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int len;
int pp[101];
char s[101][105];

int comp(const void *p, const void *q)
{
	return strcmp(s[*(int*)p]+len, s[*(int*)q]+len);
}

int main()
{
	int n, i, j;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", &s[i]);
			pp[i] = i;
		}
		for(i=0; i<100; i++)
		{
			len = i;
			qsort(pp, n, sizeof(int), comp);
			for(j=1; j<n; j++)
			{
				if(strcmp(s[pp[j]]+len, s[pp[j-1]]+len) == 0 || s[pp[j]][len] == 0 || s[pp[j-1]][len] == 0)
				{
					break;
				}
			}
			if(j < n)
			{
				break;
			}
		}
		printf("%d\n", len-1);
	}
	return 0;
}

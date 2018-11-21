#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char ary[100][101], str[100];

int comp(const void *p, const void *q)
{
	return strcmp((char*)p, (char*)q);
}

int main()
{
	int count, p, t, i, j, c;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &p, &t);
		gets(str);
		memset(ary, 1, sizeof(ary));
		for(i=0; i<p; i++)
		{
			ary[i][t] = 0;
		}
		while(gets(str))
		{
			if(sscanf(str, "%d%d", &i, &j) == 2)
			{
				ary[i-1][j-1] = 2;
			}
			else
			{
				break;
			}
		}
		if(p)
		{
			qsort(ary, p, sizeof(ary[0]), comp);
			c = 1;
			for(i=1; i<p; i++)
			{
				if(strcmp(ary[i], ary[i-1]))
				{
					c++;
				}
			}
			printf("%d\n", c);
		}
		else
		{
			printf("0\n");
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}

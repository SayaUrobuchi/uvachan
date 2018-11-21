#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int tbl[30], ptr[30], res[30];
char buf[2000000];

int comp(const void *p, const void *q)
{
	return tbl[*(int*)p] == tbl[*(int*)q] ? *(int*)p - *(int*)q : tbl[*(int*)q] - tbl[*(int*)p];
}

int main()
{
	int count, i, j, k, l, n;
	char *p;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(tbl, 0, sizeof(tbl));
		while(scanf("%s", buf) == 1)
		{
			for(p=buf; *p; p++)
			{
				if(*p == '#')
				{
					break;
				}
				tbl[*p-'A']++;
			}
			if(*p == '#')
			{
				break;
			}
		}
		for(i=0; i<n; i++)
		{
			ptr[i] = i;
		}
		qsort(ptr, n, sizeof(int), comp);
		for(i=0, j=n-1, k=0; k<n; )
		{
			if(i == j)
			{
				res[i] = ptr[k++];
			}
			else
			{
				if(tbl[ptr[k]] != tbl[ptr[k+1]])
				{
					if(ptr[k] < ptr[k+1])
					{
						res[i++] = ptr[k];
						for(l=k+2; l<n&&tbl[ptr[l]]==tbl[ptr[k+1]]; l++);
						res[j--] = ptr[--l];
						for(; l>k+1; l--)
						{
							ptr[l] = ptr[l-1];
						}
					}
					else
					{
						res[i++] = ptr[k+1];
						res[j--] = ptr[k];
					}
				}
				else
				{
					res[i++] = ptr[k];
					for(l=k+2; l<n&&tbl[ptr[l]]==tbl[ptr[k+1]]; l++);
					res[j--] = ptr[--l];
					for(; l>k+1; l--)
					{
						ptr[l] = ptr[l-1];
					}
				}
				k += 2;
			}
		}
		printf("%c", res[0]+'A');
		for(i=1; i<n; i++)
		{
			printf(" %c", res[i]+'A');
		}
		printf("\n%d", tbl[res[0]]);
		for(i=1; i<n; i++)
		{
			printf(" %d", tbl[res[i]]);
		}
		printf("\n");
	}
	return 0;
}


#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int index[101], ptr[10501];
char str[1001], tbl[101][129], ary[101][1001], res[10502][2500];

int comp(const void *p, const void *q)
{
	if(!strcmp(tbl[*(int*)p], tbl[*(int*)q]))
	{
		return strcmp(ary[*(int*)p], ary[*(int*)q]);
	}
	return strcmp(tbl[*(int*)p], tbl[*(int*)q]);
}

int comp2(const void *p, const void *q)
{
	return strcmp(res[*(int*)p], res[*(int*)q]);
}

int main()
{
	int count, n, i, j, k;
	scanf("%d", &count);
	gets(str);
	gets(str);
	while(count--)
	{
		n = 0;
		memset(tbl, 1, sizeof(tbl));
		while(gets(ary[n]))
		{
			if(!ary[n][0])
			{
				break;
			}
			for(i=0; ary[n][i]; i++)
			{
				if(ary[n][i] != ' ')
				{
					tbl[n][ary[n][i]]++;
				}
			}
			tbl[n][128] = 0;
			index[n] = n;
			n++;
		}
		qsort(index, n, sizeof(int), comp);
		for(i=0, k=0; i<n; i++)
		{
			for(j=i+1; j<n; j++)
			{
				if(strcmp(tbl[index[i]], tbl[index[j]]))
				{
					break;
				}
				ptr[k] = k;
				sprintf(res[k++], "%s = %s", ary[index[i]], ary[index[j]]);
			}
		}
		qsort(ptr, k, sizeof(int), comp2);
		for(i=0; i<k; i++)
		{
			printf("%s\n", res[ptr[i]]);
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}

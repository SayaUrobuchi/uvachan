#include <stdio.h>
#include <stdlib.h>

int ary[100005], ptr[100005];
char str[100005][51];

int comp(const void *p, const void *q)
{
	if(ary[*(int*)p] == ary[*(int*)q])
	{
		return *(int*)p - *(int*)q;
	}
	return ary[*(int*)p] - ary[*(int*)q];
}

int main()
{
	int n, i, t;
	char *p;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", str[i]);
			ptr[i] = i;
			for(p=str[i], t=0; *p; p++)
			{
				t += *p - 48;
			}
			ary[i] = t;
		}
		qsort(ptr, n, sizeof(int), comp);
		printf("%s", str[ptr[0]]);
		for(i=1; i<n; i++)
		{
			printf(" %s", str[ptr[i]]);
		}
		printf("\n");
	}
	return 0;
}

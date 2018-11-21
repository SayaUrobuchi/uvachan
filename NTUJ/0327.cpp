#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int m, age[150], num[150], map[150][150], id[150], diff[150][150], queue[150];
char name[150][150], s1[150], s2[150];

int comp(const void *p, const void *q)
{
	if(age[*(int*)p] == age[*(int*)q])
	{
		return strcmp(name[*(int*)p], name[*(int*)q]);
	}
	return age[*(int*)q] - age[*(int*)p];
}

int search(char *s)
{
	int i;
	for(i=0; i<m; i++)
	{
		if(strcmp(name[i], s) == 0)
		{
			return i;
		}
	}
	strcpy(name[m++], s);
	return i;
}

int main()
{
	int count, cas, n, i, j, k, desc, n1, n2, now, ag;
	cas = 0;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		memset(num, 0, sizeof(num));
		for(i=0, m=0; i<n; i++)
		{
			scanf("%s%s%d", s1, s2, &desc);
			id[i] = i;
			n1 = search(s1);
			n2 = search(s2);
			diff[n1][num[n1]] = desc;
			map[n1][num[n1]++] = n2;
		}
		id[n] = n;
		queue[0] = search("Ted");
		age[queue[0]] = 100;
		for(i=0, j=1; i<j; i++)
		{
			now = queue[i];
			ag = age[queue[i]];
			for(k=0; k<num[now]; k++)
			{
				queue[j++] = map[now][k];
				age[map[now][k]] = ag - diff[now][k];
			}
		}
		qsort(id, n+1, sizeof(int), comp);
		printf("DATASET %d\n", ++cas);
		for(i=1; i<=n; i++)
		{
			printf("%s %d\n", name[id[i]], age[id[i]]);
		}
	}
	return 0;
}

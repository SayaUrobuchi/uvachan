#include <stdio.h>
#include <string.h>

int ary[1005][128];
int tbl[128];
char dic[1005][25];
char buf[2008];

int main()
{
	int count, n, i, j;
	char *ptr;
	scanf("%d", &count);
	while(count--)
	{
		memset(ary, 0, sizeof(ary));
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%s", dic[i]);
			for(ptr=dic[i]; *ptr; ptr++)
			{
				ary[i][*ptr]++;
			}
		}
		while(scanf("%s", buf) == 1)
		{
			if(!strcmp(buf, "END"))
			{
				break;
			}
			memset(tbl, 0, sizeof(tbl));
			for(ptr=buf; *ptr; ptr++)
			{
				tbl[*ptr]++;
			}
			printf("Anagrams for: %s\n", buf);
			for(i=0, j=1; i<n; i++)
			{
				if(!memcmp(tbl, ary[i], sizeof(tbl)))
				{
					printf("%3d) %s\n", j++, dic[i]);
				}
			}
			if(j == 1)
			{
				printf("No anagrams for: %s\n", buf);
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}

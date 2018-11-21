#include <stdio.h>
#include <string.h>

char str[25][10], *ptr[25], *temp, used[25];

int main()
{
	int count, n, m, i, j, p, q;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &m);
		for(i=1; i<=n; i++)
		{
			scanf("%s", str[i]);
			ptr[i] = NULL;
		}
		memset(used, 0, sizeof(used));
		while(m--)
		{
			scanf("%d%d", &p, &q);
			used[p] = 1;
			ptr[q] = str[p];
		}
		for(i=1, j=1; i<=n; i++)
		{
			if(ptr[i] == NULL)
			{
				for(; used[j]; j++);
				ptr[i] = str[j++];
			}
		}
		printf("%s", ptr[1]);
		for(i=2; i<=n; i++)
		{
			printf(" %s", ptr[i]);
		}
		printf("\n");
	}
	return 0;
}

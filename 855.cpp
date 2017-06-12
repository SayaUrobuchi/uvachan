#include <stdio.h>
#include <string.h>

int sortx[1001], sorty[1001];

int main()
{
	int count, f, n, i, j;
	scanf("%d", &count);
	while(count--)
	{
		memset(sortx, 0, sizeof(sortx));
		memset(sorty, 0, sizeof(sorty));
		scanf("%d%d%d", &i, &j, &f);
		n = (f+1) / 2;
		while(f--)
		{
			scanf("%d%d", &i, &j);
			sortx[i]++;
			sorty[j]++;
		}
		for(i=1, j=0; ; i++)
		{
			j += sortx[i];
			if(j >= n)
			{
				printf("(Street: %d, Avenue: ", i);
				break;
			}
		}
		for(i=1, j=0; ; i++)
		{
			j += sorty[i];
			if(j >= n)
			{
				printf("%d)\n", i);
				break;
			}
		}
	}
	return 0;
}

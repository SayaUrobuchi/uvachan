#include <stdio.h>
#include <string.h>

int list[35];

int main()
{
	int cas, n, i, j, k, l, temp;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(cas)
		{
			printf("\n");
		}
		cas = 1;
		for(i=0, k=2; i<n; i++)
		{
			printf("1");
			for(j=1; j<n; j++, k++)
			{
				printf(" %d", k);
			}
			printf("\n");
		}
		for(i=1; i<n; i++)
		{
			printf("2");
			for(j=1, k=n+i; j<n; j++, k+=n-1)
			{
				printf(" %d", k);
			}
			printf("\n");
		}
		for(i=2; i<n; i++)
		{
			for(j=0, k=0; j<n-1; j++)
			{
				list[j] = k;
				k += i-1;
				k %= n-1;
			}
			/*printf("****list:");
			for(j=1; j<n; j++)
			{
				printf(" %d", list[j-1]);
			}
			printf("\n");*/
			for(l=1; l<n; l++)
			{
				printf("%d", i+1);
				for(j=1, k=n+1; j<n; j++, k+=n-1)
				{
					printf(" %d", k+list[j-1]);
				}
				printf("\n");
				temp = list[0];
				for(j=1; j<n-1; j++)
				{
					list[j-1] = list[j];
				}
				list[j-1] = temp;
			}
		}
	}
	return 0;
}

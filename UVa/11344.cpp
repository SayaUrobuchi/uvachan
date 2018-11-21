#include <stdio.h>

int num[10000];
char str[10000];

int main()
{
	int count, n, m, i, j, k, flag;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d", str, &n);
		for(i=0; str[i]; i++)
		{
			num[i] = str[i] - 48;
		}
		for(i=0, flag=0; i<n; i++)
		{
			scanf("%d", &m);
			if(!flag)
			{
				for(j=0, k=0; str[j]; j++)
				{
					k *= 10;
					k += num[j];
					k %= m;
				}
				flag = k;
			}
		}
		if(flag)
		{
			printf("%s - Simple.\n", str);
		}
		else
		{
			printf("%s - Wonderful.\n", str);
		}
	}
	return 0;
}

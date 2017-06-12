#include <stdio.h>
#include <string.h>

int ary[100001], nei[100001];
char tmp[10000001];

int main()
{
	int n, c, i, j, sum;
	while(scanf("%d%d", &c, &n) == 2)
	{
		if(!c && !n)
		{
			break;
		}
		memset(ary, 0, 4 * c);
		ary[0] = 1;
		for(i=1, sum=0; ; i++)
		{
			scanf("%d", &nei[i]);
			sum += nei[i];
			sum %= c;
			if(ary[sum])
			{
				for(j=ary[sum]; j<i; j++)
				{
					printf("%d ", j);
				}
				printf("%d\n", j);
				gets(tmp);
				break;
			}
			else
			{
				ary[sum] = i + 1;
			}
		}
	}
	return 0;
}

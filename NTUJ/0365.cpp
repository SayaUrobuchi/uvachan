#include <stdio.h>
#include <string.h>

int dis[2500];
char str[2500][10];

int main()
{
	int n, i, j, k, c, res;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		memset(dis, 0, sizeof(dis));
		for(i=0; i<n; i++)
		{
			scanf("%s", str[i]);
			for(j=0; j<i; j++)
			{
				for(k=0, c=0; str[i][k]; c+=(str[i][k]!=str[j][k]), k++);
				dis[i] += c;
				dis[j] += c;
			}
		}
		for(i=0, res=2147483647; i<n; i++)
		{
			if(dis[i] < res)
			{
				res = dis[i];
			}
		}
		printf("The highest possible quality is 1/%d.\n", res);
	}
	return 0;
}

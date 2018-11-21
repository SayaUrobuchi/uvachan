#include <stdio.h>

int px[1050], py[1050], pp[1050];

int dis(int x, int y)
{
	return x*x+y*y;
}

int main()
{
	int count, n, i, j, temp, ans;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			scanf("%d%d%d", &px[i], &py[i], &pp[i]);
		}
		for(i=-10000, ans=0; i<=10000; i++)
		{
			for(j=0, temp=0; j<n; j++)
			{
				if(dis(px[j]-i, py[j]) <= 1000000)
				{
					temp += pp[j];
				}
			}
			if(temp > ans)
			{
				ans = temp;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

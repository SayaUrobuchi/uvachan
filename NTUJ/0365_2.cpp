#include <stdio.h>
#include <string.h>

int used[2500], dis[2500];
char str[2500][10];

int getd(int p, int q)
{
	int i, r;
	for(i=0, r=0; i<7; r+=(str[p][i]!=str[q][i]), i++);
	return r;
}

int main()
{
	int n, i, r, md, t, temp;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%s", str[i]);
			dis[i] = 2147483647;
		}
		memset(used, 0, sizeof(used));
		dis[0] = 0;
		for(r=0; ; )
		{
			for(i=0, md=2147483647; i<n; i++)
			{
				if(used[i] == 0 && dis[i] < md)
				{
					md = dis[i];
					temp = i;
				}
			}
			if(md == 2147483647)
			{
				break;
			}
			used[temp] = 1;
			r += md;
			for(i=0; i<n; i++)
			{
				if(used[i] == 0)
				{
					if(dis[i] > (t=getd(temp, i)))
					{
						dis[i] = t;
					}
				}
			}
		}
		printf("The highest possible quality is 1/%d.\n", r);
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

int dis[505], used[505], num[505];

typedef struct node
{
	int t, l;
};

node map[505][505];

int main()
{
	int cas, n, m, i, j, k, l, t, min, temp, type, type2;
	double max;
	cas = 0;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(num, 0, sizeof(num));
		while(m--)
		{
			scanf("%d%d%d", &i, &j, &l);
			map[i][num[i]].t = j;
			map[i][num[i]++].l = l;
			map[j][num[j]].t = i;
			map[j][num[j]++].l = l;
		}
		for(i=2; i<=n; i++)
		{
			dis[i] = 1000000000;
			used[i] = 0;
		}
		dis[1] = 0;
		used[1] = 0;
		max = -1;
		for(k=0; k<n; k++)
		{
			for(i=1, min=1000000000; i<=n; i++)
			{
				if(!used[i] && dis[i] < min)
				{
					min = dis[i];
					temp = i;
				}
			}
			used[temp] = 1;
			if(dis[temp] > max)
			{
				max = dis[temp];
				type = 0;
			}
			for(i=0; i<num[temp]; i++)
			{
				t = map[temp][i].t;
				l = map[temp][i].l;
				if(!used[t])
				{
					if(dis[t] > dis[temp] + l)
					{
						dis[t] = dis[temp] + l;
					}
				}
				else
				{
					if(dis[temp] + (dis[t]+l-dis[temp])/2.0 > max)
					{
						max = dis[temp] + (dis[t]+l-dis[temp])/2.0;
						type = t;
						type2 = temp;
					}
				}
			}
		}
		printf("System #%d\n", ++cas);
		if(type)
		{
			printf("The last domino falls after %.1lf seconds, between key dominoes %d and %d.\n\n", max, type2, type);
		}
		else
		{
			printf("The last domino falls after %.1lf seconds, at key domino %d.\n\n", max, temp);
		}
	}
	return 0;
}

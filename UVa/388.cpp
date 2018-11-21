#include <stdio.h>
#include <string.h>
#include <math.h>

#define SHIFT 64

int map[27][27];
int dis[27];
int queue[27];
char buf1[1001], buf2[1001];
double value[27];

int main()
{
	int n, i, j, k, id, now, idtemp;
	double v, temp, maximum;
	while(scanf("%d", &n) == 1)
	{
		memset(map, 0, sizeof(map));
		for(i=0; i<n; i++)
		{
			scanf("%s%lf%s", buf1, &v, buf2);
			id = buf1[0] - SHIFT;
			value[id] = v;
			for(j=0; buf2[j]; j++)
			{
				if(buf2[j] == '*')
				{
					map[id][0] = map[0][id] = 1;
				}
				else
				{
					map[id][buf2[j]-SHIFT] = map[buf2[j]-SHIFT][id] = 1;
				}
			}
		}
		memset(dis, 0, sizeof(dis));
		dis[0] = 1;
		queue[0] = 0;
		for(i=0, j=1; i<j; i++)
		{
			now = queue[i];
			for(k=0; k<=26; k++)
			{
				if(map[now][k] && !dis[k])
				{
					dis[k] = dis[now] + 1;
					queue[j++] = k;
				}
			}
		}
		for(i=1, maximum=0; i<=26; i++)
		{
			if(dis[i])
			{
				/*if((temp=(1.0 / pow(0.95, dis[i]-2))*value[i]) > maximum)
				{
					maximum = temp;
					idtemp = i;
				}*/
				if((temp=pow(0.95, dis[i]-2)*value[i]) > maximum)
				{
					maximum = temp;
					idtemp = i;
				}
			}
		}
		printf("Import from %c\n", idtemp+SHIFT);
	}
	return 0;
}

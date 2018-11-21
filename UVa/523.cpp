#include <stdio.h>
#include <string.h>

int path[200][200], connect[200][200], cost[200];

void calc(int left, int right)
{
	if(connect[left][right] == -1) return;
	calc(left, connect[left][right]);
	printf("-->%d", connect[left][right] + 1);
	calc(connect[left][right], right);
	return;
}

int main()
{
	char tmp, buf[100];
	int count, i, j, k, l, start, target;
	scanf("%d", &count);
	while(count--)
	{
		k=0;
		while(scanf("%d%c", &path[0][k], &tmp)==2)
		{
			connect[0][k++] = -1;
			if(tmp == 10) break;
		}
		for(i=1; i<k; i++)
		{
			for(j=0; j<k; j++)
			{
				scanf("%d", &path[i][j]);
				connect[i][j] = -1;
			}
		}
		for(i=0; i<k; i++)
		{
			scanf("%d", &cost[i]);
		}
		for(l=0; l<k; l++)
		{
			for(i=0; i<k; i++)
			{
				for(j=0; j<k; j++)
				{
					if(path[i][l] > 0 && path[l][j] > 0)
					{
						if(path[i][j] == -1 || path[i][l] + path[l][j] + cost[l] < path[i][j])
						{
							path[i][j] = path[i][l] + path[l][j] + cost[l];
							connect[i][j] = l;
						}
					}
				}
			}
		}
		gets(buf);
		tmp = 0;
		while(gets(buf))
		{
			if(!strlen(buf)) break;
			if(tmp) printf("\n");
			tmp = 1;
			sscanf(buf, "%d%d", &start, &target);
			printf("From %d to %d :\nPath: %d", start, target, start);
			calc(start - 1, target - 1);
			printf("-->%d\nTotal cost : %d\n", target, path[start - 1][target - 1]);
		}
		if(count) printf("\n");
	}
	return 0;
}

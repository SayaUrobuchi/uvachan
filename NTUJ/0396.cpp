#include <stdio.h>
#include <string.h>

int num[30];
int list[30][30];
int assigned[30];
int sused[30], pused[30];
int xmin[30], xmax[30];
int ymin[30], ymax[30];
int px[30], py[30];

int fill(int);

int assign(int now)
{
	if(!assigned[now])
	{
		return 1;
	}
	else if(!sused[assigned[now]])
	{
		return fill(assigned[now]);
	}
	return 0;
}

int fill(int now)
{
	int i, target;
	sused[now] = 1;
	for(i=0; i<num[now]; i++)
	{
		if(!pused[target=list[now][i]])
		{
			pused[target] = 1;
			if(assign(target))
			{
				assigned[target] = now;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int cas, n, i, j, k, ans, temp;
	cas = 0;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		for(i=1; i<=n; i++)
		{
			scanf("%d%d%d%d", &xmin[i], &xmax[i], &ymin[i], &ymax[i]);
		}
		memset(num, 0, sizeof(num));
		for(i=1; i<=n; i++)
		{
			scanf("%d%d", &px[i], &py[i]);
			for(j=1; j<=n; j++)
			{
				if(px[i] > xmin[j] && px[i] < xmax[j] && py[i] > ymin[j] && py[i] < ymax[j])
				{
					list[j][num[j]++] = i;
				}
			}
		}
		printf("Heap %d\n", ++cas);
		for(i=1, ans=0; i<=n; i++)
		{
			for(j=0, temp=0; j<num[i]; j++)
			{
				memset(assigned, 0, sizeof(assigned));
				assigned[list[i][j]] = i;
				for(k=1; k<=n; k++)
				{
					if(i != k)
					{
						memset(pused, 0, sizeof(pused));
						memset(sused, 0, sizeof(sused));
						pused[list[i][j]] = 1;
						if(!fill(k))
						{
							break;
						}
					}
				}
				if(k > n)
				{
					if(temp)
					{
						break;
					}
					temp = list[i][j];
				}
			}
			if(temp && j >= num[i])
			{
				if(ans)
				{
					printf(" ");
				}
				ans = 1;
				printf("(%c,%d)", i+64, temp);
			}
		}
		if(!ans)
		{
			printf("none");
		}
		printf("\n\n");
	}
	return 0;
}

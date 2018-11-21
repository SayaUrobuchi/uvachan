#include <stdio.h>
#include <string.h>

#define INF 2147483647

int map[5001][5001], num[5001], ldis[5001][5001], minlist[5001], maxlist[5001];

int getmax(int p, int q)
{
	if(p > q)
	{
		return p;
	}
	return q;
}

int getdis(int p, int q)
{
	int i, t;
	if(ldis[p][q])
	{
		return ldis[p][q];
	}
	/*printf("%d %d\n", p, q);*/
	t = map[p][q];
	ldis[p][q] = 1;
	for(i=0; i<num[t]; i++)
	{
		if(map[t][i] != p)
		{
			ldis[p][q] = getmax(ldis[p][q], getdis(t, i)+1);
		}
	}
	return ldis[p][q];
}

int main()
{
	int n, i, j, min, max, minp, maxp, temp;
	while(scanf("%d", &n) == 1)
	{
		for(i=1; i<=n; i++)
		{
			scanf("%d", &num[i]);
			for(j=0; j<num[i]; j++)
			{
				scanf("%d", &map[i][j]);
			}
			memset(ldis[i], 0, num[i]*sizeof(int));
		}
		for(i=1, min=INF, max=-1, minp=maxp=0; i<=n; i++)
		{
			for(j=0, temp=0; j<num[i]; j++)
			{
				temp = getmax(temp, getdis(i, j));
			}
			/*printf("XDDD %d %d\n", i, temp);*/
			if(temp > max)
			{
				max = temp;
				maxp = 0;
				maxlist[maxp++] = i;
			}
			else if(temp == max)
			{
				maxlist[maxp++] = i;
			}
			if(temp < min)
			{
				min = temp;
				minp = 0;
				minlist[minp++] = i;
			}
			else if(temp == min)
			{
				minlist[minp++] = i;
			}
		}
		printf("Best Roots  :");
		for(i=0; i<minp; i++)
		{
			printf(" %d", minlist[i]);
		}
		printf("\n");
		printf("Worst Roots :");
		for(i=0; i<maxp; i++)
		{
			printf(" %d", maxlist[i]);
		}
		printf("\n");
	}
	return 0;
}

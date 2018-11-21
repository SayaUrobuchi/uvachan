#include <stdio.h>
#include <string.h>

int map[21][1001], num[21];
int category[21];
int catused[21], probused[1001];
int cat[1001], prob[21][101];

int catfill(int, int);

int getprob(int probnum)
{
	int i, catnum;
	if(cat[probnum])
	{
		catnum = cat[probnum] - 1;
		if(catused[catnum])
		{
			return 0;
		}
		for(i=0; ; i++)
		{
			if(prob[catnum][i] == probnum)
			{
				return catfill(catnum, i);
			}
		}
	}
	else
	{
		return 1;
	}
}

int catfill(int catnum, int catloc)
{
	int i, target;
	/*printf("now fill cat %d, num %d\n", catnum, num[catnum]);*/
	for(i=0; i<num[catnum]; i++)
	{
		/*printf("cat %d searches prob %d\n", catnum, map[catnum][i]);*/
		if(!probused[target=map[catnum][i]])
		{
			probused[target] = 1;
			if(cat[target] - 1 != catnum && getprob(target))
			{
				prob[catnum][catloc] = target;
				cat[target] = catnum + 1;
				return 1;
			}
		}
	}
	return 0;
}

int main()
{
	int n, m, i, j, temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			scanf("%d", &category[i]);
		}
		memset(num, 0, sizeof(num));
		memset(cat, 0, sizeof(cat));
		for(i=0; i<m; i++)
		{
			scanf("%d", &temp);
			while(temp--)
			{
				scanf("%d", &j);
				j--;
				map[j][num[j]++] = i;
			}
		}
		for(i=0; i<n; i++)
		{
			for(j=0; j<category[i]; j++)
			{
				memset(probused, 0, sizeof(probused));
				memset(catused, 0, sizeof(catused));
				catused[i] = 1;
				if(!catfill(i, j))
				{
					/*printf("Failed when %d %d\n", i, j);*/
					break;
				}
			}
			if(j < category[i])
			{
				break;
			}
		}
		if(i < n)
		{
			printf("0\n");
		}
		else
		{
			printf("1\n");
			for(i=0; i<n; i++)
			{
				printf("%d", prob[i][0]+1);
				for(j=1; j<category[i]; j++)
				{
					printf(" %d", prob[i][j]+1);
				}
				printf("\n");
			}
		}
	}
	return 0;
}

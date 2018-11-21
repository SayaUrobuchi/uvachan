#include <stdio.h>
#include <string.h>

int puzzle[11][11], top[101], left[101], bottom[101], right[101], n, l;
char image[101][26][26], result[255];

int dfs(int x, int y)
{
	int i, topmatch, leftmatch, bottommatch, rightmatch;
	if(y == n)
	{
		x++;
		y = 0;
	}
	if(x == n)
	{
		return 1;
	}
	if(!x)
	{
		topmatch = 0;
	}
	else
	{
		topmatch = bottom[puzzle[x-1][y]];
	}
	if(!y)
	{
		leftmatch = 0;
	}
	else
	{
		leftmatch = right[puzzle[x][y-1]];
	}
	if(x == n-1)
	{
		bottommatch = 0;
	}
	else
	{
		bottommatch = 10;
	}
	if(y == n-1)
	{
		rightmatch = 0;
	}
	else
	{
		rightmatch = 10;
	}
	for(i=0; i<l; i++)
	{
		if(top[i] == -topmatch && left[i] == -leftmatch && (bottommatch == 10 || bottommatch == -bottom[i]) && (rightmatch == 10 || rightmatch == -right[i]))
		{
			puzzle[x][y] = i;
			if(dfs(x, y+1))
			{
				return 1;
			}
		}
	}
}

int main()
{
	int count, i, j, k, h, w;
	char buf[100];
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &n, &h, &w);
		gets(buf);
		for(k=0, l=n*n; k<l; k++)
		{
			for(i=0; i<h; i++)
			{
				gets(image[k][i]);
			}
			scanf("%d%d%d%d", &top[k], &left[k], &bottom[k], &right[k]);
			gets(buf);
			gets(buf);
		}
		dfs(0, 0);
		for(i=0; i<n; i++)
		{
			for(j=0; j<h; j++)
			{
				result[0] = 0;
				for(k=0; k<n; k++)
				{
					strcat(result, image[puzzle[i][k]][j]);
				}
				printf("%s\n", result);
			}
		}
		if(count)
		{
			printf("\n");
		}
	}
	return 0;
}

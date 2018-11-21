#include <stdio.h>

int n;
int map[101][101];

void rotate1(int left, int right)
{
	int i, j, temp;
	for(i=left; i<right; i++)
	{
		temp = map[left][i];
		map[left][i] = map[right-1][i];
		map[right-1][i] = temp;
	}
	for(i=left+1, j=right-2; i<j; i++, j--)
	{
		temp = map[i][left];
		map[i][left] = map[j][left];
		map[j][left] = temp;
		temp = map[i][right-1];
		map[i][right-1] = map[j][right-1];
		map[j][right-1] = temp;
	}
}

void rotate2(int left, int right)
{
	int i, j, temp;
	for(i=left; i<right; i++)
	{
		temp = map[i][left];
		map[i][left] = map[i][right-1];
		map[i][right-1] = temp;
	}
	for(i=left+1, j=right-2; i<j; i++, j--)
	{
		temp = map[left][i];
		map[left][i] = map[left][j];
		map[left][j] = temp;
		temp = map[right-1][i];
		map[right-1][i] = map[right-1][j];
		map[right-1][j] = temp;
	}
}

void rotate3(int left, int right)
{
	int i, j, temp;
	for(i=left; i<right; i++)
	{
		temp = map[i][left];
		map[i][left] = map[left][i];
		map[left][i] = temp;
	}
	for(i=left+1; i<right; i++)
	{
		temp = map[right-1][i];
		map[right-1][i] = map[i][right-1];
		map[i][right-1] = temp;
	}
}

void rotate4(int left, int right)
{
	int i, j, temp;
	for(i=left, j=right-1; i<right; i++, j--)
	{
		temp = map[left][i];
		map[left][i] = map[j][right-1];
		map[j][right-1] = temp;
	}
	for(i=left+1, j=right-2; i<right; i++, j--)
	{
		temp = map[i][left];
		map[i][left] = map[right-1][j];
		map[right-1][j] = temp;
	}
}

int main()
{
	int count, m, i, j, in;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0; i<n; i++)
		{
			for(j=0; j<n; j++)
			{
				scanf("%d", &map[i][j]);
			}
		}
		for(i=0, j=n; i<j; i++, j--)
		{
			scanf("%d", &m);
			while(m--)
			{
				scanf("%d", &in);
				if(in == 1)
				{
					rotate1(i, j);
				}
				else if(in == 2)
				{
					rotate2(i, j);
				}
				else if(in == 3)
				{
					rotate3(i, j);
				}
				else
				{
					rotate4(i, j);
				}
			}
		}
		for(i=0; i<n; i++)
		{
			printf("%d", map[i][0]);
			for(j=1; j<n; j++)
			{
				printf(" %d", map[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}

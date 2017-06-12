#include <stdio.h>

int height, j;
int ary[50001];

int bisearch()
{
	int left, right, center;
	left = 0;
	right = j;
	for(center=(left+right)/2; ; center=(left+right)/2)
	{
		if(ary[center] < height)
		{
			left = center + 1;
			if(left > right)
			{
				return center;
			}
		}
		else
		{
			right = center - 1;
			if(left > right)
			{
				return right;
			}
		}
	}
}

int main()
{
	int n, m, i, index;
	scanf("%d%d", &n, &ary[0]);
	for(i=1, j=0; i<n; i++)
	{
		scanf("%d", &height);
		if(height > ary[j])
		{
			ary[++j] = height;
		}
	}
	scanf("%d", &m);
	while(m--)
	{
		scanf("%d", &height);
		index = bisearch();
		if(index == -1)
		{
			putchar('X');
		}
		else
		{
			printf("%d", ary[index]);
		}
		index++;
		if(ary[index] == height)
		{
			index++;
		}
		if(index > j)
		{
			printf(" X\n");
		}
		else
		{
			printf(" %d\n", ary[index]);
		}
	}
	scanf(" ");
	return 0;
}

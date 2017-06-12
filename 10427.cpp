#include <stdio.h>

int tbl[11];
int times[11];

int bisearch(int target, int left, int right)
{
	int center;
	while(1)
	{
		center = left + right;
		center /= 2;
		if(tbl[center] == target)
		{
			return center - 1;
		}
		else if(tbl[center] > target)
		{
			right = center - 1;
			if(left > right)
			{
				return center - 1;
			}
		}
		else
		{
			left = center + 1;
			if(left > right)
			{
				return center;
			}
		}
	}
}

int main()
{
	int n, m, i, j, temp;
	char str[100];
	times[0] = 1;
	for(i=1, j=9; i<11; i++, j*=10)
	{
		tbl[i] = tbl[i-1] + j * i;
		times[i] = times[i-1] * 10;
	}
	while(scanf("%d", &n) == 1)
	{
		temp = bisearch(n, 1, 9);
		n -= tbl[temp];
		m = (n-1) / (temp+1);
		m += times[temp];
		sprintf(str, "%d", m);
		printf("%c\n", str[(n-1)%(temp+1)]);
	}
	return 0;
}

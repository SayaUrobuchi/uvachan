#include <stdio.h>
#include <stdlib.h>

int times;
int num[9];
int ary[9][10000];

int comp(int p, int q)
{
	return (p+q)*(p+q) - (times*p + q);
}

int bisearch(int left, int right, int target)
{
	int center, cmp;
	if(left > right)
	{
		return -1;
	}
	center = left + right;
	center /= 2;
	cmp = comp(target, center);
	if(!cmp)
	{
		return center;
	}
	else if(cmp > 0)
	{
		return bisearch(left, center-1, target);
	}
	return bisearch(center+1, right, target);
}

int main()
{
	int n, i, j, temp;
	for(i=2, times=10; i<=8; i+=2, times*=10)
	{
		ary[i][0] = 0;
		ary[i][1] = 1;
		num[i] = 2;
		for(j=1; j<times; j++)
		{
			if((temp=bisearch(0, times-1, j)) != -1)
			{
				ary[i][num[i]++] = j*times + temp;
			}
		}
	}
	/*printf("FINISH!!\n");*/
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<num[n]; i++)
		{
			printf("%0*d\n", n, ary[n][i]);
		}
	}
	return 0;
}

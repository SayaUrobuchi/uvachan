#include <stdio.h>

int n, temp, alive[2000005], ary[2000005], tbl[2000005];

int build(int left, int right)
{
	int center, temp;
	if(left > right)
	{
		return 0;
	}
	center = ((left + right) >> 1);
	alive[center] = (center & 1);
	if(left == right)
	{
		return ary[center]=alive[center];
	}
	temp = ary[center] = build(left, center-1) + alive[center];
	temp += build(center+1, right);
	return temp;
}

void del(int left, int right, int target)
{
	int center;
	center = ((left + right) >> 1);
	if(ary[center] == target && alive[center])
	{
		alive[center] = 0;
		ary[center]--;
		n--;
	}
	else if(ary[center] < target)
	{
		del(center+1, right, target-ary[center]);
	}
	else
	{
		del(left, center-1, target);
		ary[center]--;
	}
}

void travel(int left, int right)
{
	int center;
	if(left > right)
	{
		return;
	}
	center = ((left + right) >> 1);
	travel(left, center-1);
	if(alive[center])
	{
		tbl[n++] = center;
	}
	travel(center+1, right);
}

void bisearch(int left, int right, int target)
{
	int center;
	if(left > right)
	{
		return;
	}
	center = ((left + right) >> 1);
	if(tbl[center] > target)
	{
		bisearch(left, center-1, target);
	}
	else
	{
		temp = center;
		bisearch(center+1, right, target);
	}
}

int main()
{
	int i, j, m;
	build(1, 2000000);
	for(i=3, n=1000000; i<=n; i+=2)
	{
		if(alive[i])
		{
			for(j=i; j<=n; j+=i-1)
			{
				del(1, 2000000, j);
			}
		}
	}
	n = 0;
	travel(1, 2000000);
	/*printf("FINISH!!\n");*/
	/*for(i=0; i<20; i++)
	{
		printf("%d\n", tbl[i]);
	}*/
	while(scanf("%d", &m) == 1)
	{
		if(m % 2 == 1)
		{
			printf("%d is not the sum of two luckies!\n", m);
		}
		else
		{
			for(bisearch(0, n-1, m>>1), i=temp; i>=0; i--)
			{
				if(alive[m-tbl[i]])
				{
					printf("%d is the sum of %d and %d.\n", m, tbl[i], m-tbl[i]);
					break;
				}
			}
			if(i < 0)
			{
				printf("%d is not the sum of two luckies!\n", m);
			}
		}
	}
	return 0;
}

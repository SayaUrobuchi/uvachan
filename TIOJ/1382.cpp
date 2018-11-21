#include <stdio.h>

int left[100050], del[100050], f;

void build(int p, int q)
{
	int center;
	if(p > q)
	{
		return;
	}
	center = ((p+q) >> 1);
	left[center] = center-p;
	del[center] = 0;
	build(p, center-1);
	build(center+1, q);
}

void search(int p, int q, int m)
{
	int center;
	center = ((p+q) >> 1);
	if(m == left[center] && del[center] == 0)
	{
		del[center] = 1;
		if(f)
		{
			printf(" ");
		}
		f = 1;
		printf("%d", center);
		return;
	}
	else if(m < left[center])
	{
		search(p, center-1, m);
		left[center]--;
	}
	else
	{
		search(center+1, q, m-left[center]-1+del[center]);
	}
}

int main()
{
	int n, m, i, temp;
	while(scanf("%d", &n) == 1)
	{
		build(1, n);
		for(i=0, f=0, temp=0; i<n; i++)
		{
			scanf("%d", &m);
			temp += m-1;
			temp %= (n-i);
			search(1, n, temp);
		}
		printf("\n");
	}
	return 0;
}

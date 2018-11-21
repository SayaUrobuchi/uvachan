#include <stdio.h>

int ary[500000], temp[500000];

void merge(int left, int center, int right)
{
	int p, l, r;
	for(p=0, l=left, r=center+1; l<=center&&r<=right; )
	{
		if(ary[l] < ary[r])
		{
			temp[p++] = ary[l++];
		}
		else
		{
			temp[p++] = ary[r++];
		}
	}
	for(; l<=center; l++)
	{
		temp[p++] = ary[l];
	}
	for(; r<=right; r++)
	{
		temp[p++] = ary[r];
	}
	for(p=0, l=left; l<=right; p++, l++)
	{
		ary[l] = temp[p];
	}
}

void msort(int left, int right)
{
	int center;
	if(left == right)
	{
		return;
	}
	center = left + right;
	center >>= 1;
	msort(left, center);
	msort(center+1, right);
	merge(left, center, right);
}

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		msort(0, n-1);
		printf("%d", ary[0]);
		for(i=1; i<n; i++)
		{
			printf(" %d", ary[i]);
		}
		printf("\n");
	}
	return 0;
}

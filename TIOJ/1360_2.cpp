#include <stdio.h>
#include "1360_soldier.h"

int ans[100005];

void recursion(int top, int bottom, int left, int right)
{
	int center, i, f, loc, temp;
	if(top > bottom)
	{
		return;
	}
	center = top + bottom;
	center >>= 1;
	for(i=left, f=0; i<=right; i++)
	{
		if((temp=Hey_Man(center, i)) > f)
		{
			f = temp;
			loc = i;
		}
	}
	ans[center] = f;
	recursion(top, center-1, left, loc-1);
	recursion(center+1, bottom, loc+1, right);
}

int main()
{
	int n, m, i;
	WarCraft();
	n = Find_n();
	m = Find_m();
	recursion(0, n-1, 0, m-1);
	for(i=0; i<n; i++)
	{
		Report(ans[i]);
	}
	return 0;
}

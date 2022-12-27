#include "lib1617.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int Get_Box( void );

int Med3( int a, int b, int c );

void Report( int a );

int ary[1600];

int qs(int l, int r, int req, int ref)
{
	if (l == r)
	{
		return ary[l];
	}
	int piv = l + rand() % (r-l+1);
	swap(ary[piv], ary[l]);
	int i, j;
	i = l;
	j = l+1;
	if (ref == -1)
	{
		ref = ary[j];
		++j;
		++i;
	}
	for (; j<=r; j++)
	{
		if (Med3(ref, ary[l], ary[j]) != ary[l])
		{
			++i;
			swap(ary[i], ary[j]);
		}
	}
	swap(ary[l], ary[i]);
	if (i-l == req)
	{
		return ary[i];
	}
	else if (i-l < req)
	{
		return qs(i+1, r, req-(i-l+1), ary[i]);
	}
	else
	{
		return qs(l, i-1, (i-1)-l+1-req-1, ary[i]);
	}
}

int main()
{
	srand(7268);
	int n = Get_Box();
	int i;
	for (i=1; i<=n; i++)
	{
		ary[i] = i;
	}
	int ans = qs(1, n, n>>1, -1);
	Report( ans );
	return 0;
}
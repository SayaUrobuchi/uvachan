#include <stdio.h>
#include "grader.h"

const int ARI = 1;
int dice[] = {0, 1, 1, 0, 0, 1}, dn;

void recurs(int p, int q)
{
	int mid, res;
	if (p > q)
	{
		return;
	}
	if (p == q)
	{
		Clean(p);
		return;
	}
	mid = ((p+q) >> 1);
	dn = (dn+1) % 6;
	if (dice[dn])
	{
		res = Ask(p, mid);
		if (res == ARI)
		{
			recurs(p, mid);
		}
		if (res == ARI)
		{
			res = Ask(mid+1, q);
		}
		else
		{
			res = ARI;
		}
		if (res == ARI)
		{
			recurs(mid+1, q);
		}
	}
	else
	{
		res = Ask(mid+1, q);
		if (res == ARI)
		{
			recurs(mid+1, q);
		}
		if (res == ARI)
		{
			res = Ask(p, mid);
		}
		else
		{
			res = ARI;
		}
		if (res == ARI)
		{
			recurs(p, mid);
		}
	}
}

int main()
{
	int n, m, i, j;
	dn = -1;
	Init(&n, &m);
	recurs(1, n);
	Submit();
	return 0;
}

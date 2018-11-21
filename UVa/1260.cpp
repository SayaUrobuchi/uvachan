#include <stdio.h>

#define N 1024

int res;
int ary[N], temp[N];

void msort(int p, int q)
{
	int i, j, k, r;
	if (p == q)
	{
		return;
	}
	r = ((p+q) >> 1);
	msort(p, r);
	msort(r+1, q);
	for (i=p, j=r+1, k=p; i<=r||j<=q; k++)
	{
		if (j > q || (i <= r && ary[i] <= ary[j]))
		{
			temp[k] = ary[i++];
		}
		else
		{
			temp[k] = ary[j++];
			res += i-p;
		}
	}
	for (i=p; i<=q; i++)
	{
		ary[i] = temp[i];
	}
}

int main()
{
	int count, n, i;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		res = 0;
		msort(0, n-1);
		printf("%d\n", res);
	}
	return 0;
}

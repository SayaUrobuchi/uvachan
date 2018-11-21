#include <stdio.h>

int ary[10005], tmp[10005];

void recurs(int p, int q)
{
	int i, j, t;
	if(p > q)
	{
		return;
	}
	if(p == q)
	{
		printf(" %d", ary[p]);
		return;
	}
	for(i=p+1, j=0; i<=q; i+=2, j++)
	{
		tmp[j] = ary[i];
	}
	tmp[j++] = ary[p];
	for(i=p+2; i<=q; i+=2, j++)
	{
		tmp[j] = ary[i];
	}
	for(i=p, j=0; i<=q; i++, j++)
	{
		ary[i] = tmp[j];
	}
	j = ((p+q+1)>>1);
	recurs(p, j-1);
	printf(" %d", ary[j]);
	recurs(j+1, q);
}

int main()
{
	int n, i;
	while(scanf("%d", &n) == 1)
	{
		if(n == 0)
		{
			break;
		}
		for(i=0; i<n; i++)
		{
			ary[i] = i;
		}
		printf("%d:", n);
		recurs(0, n-1);
		printf("\n");
	}
	return 0;
}

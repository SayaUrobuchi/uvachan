#include <stdio.h>

int ary[500005], buf[500005];
long long cnt;

void msort(int p, int q)
{
	int c, i, j, k;
	if(p == q)
	{
		return;
	}
	c = ((p+q)>>1);
	msort(p, c);
	msort(c+1, q);
	for(i=p, j=c+1, k=0; i<=c||j<=q; )
	{
		if(j>q || (i<=c && ary[i] <= ary[j]))
		{
			buf[k++] = ary[i++];
		}
		else
		{
			cnt += c-i+1;
			buf[k++] = ary[j++];
		}
	}
	for(i=p, j=0; i<=q; i++, j++)
	{
		ary[i] = buf[j];
	}
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
			scanf("%d", &ary[i]);
		}
		cnt = 0;
		msort(0, n-1);
		printf("%lld\n", cnt);
	}
	return 0;
}

#include <stdio.h>

int n, ary[100005];

int min(int p, int q)
{
	return p<q ? p : q;
}

int max(int p, int q)
{
	return p>q ? p : q;
}

int ab(int now)
{
	return now < 0 ? -now : now;
}

int adjust(int now)
{
	return max(0, min(now, n-1));
}

int dif(int p, int q)
{
	return ab(ary[adjust(p)]-ary[adjust(q)]);
}

void swap(int p, int q)
{
	int temp;
	temp = ary[p];
	ary[p] = ary[q];
	ary[q] = temp;
}

int calc(int p, int q)
{
	int temp;
	temp = dif(p, p-1)+dif(p, p+1)+dif(q, q-1)+dif(q, q+1);
	swap(p, q);
	temp -= dif(p, p-1)+dif(p, p+1)+dif(q, q-1)+dif(q, q+1);
	swap(p, q);
	return temp;
}

int main()
{
	int count, i, j, t, max, temp;
	scanf("%d", &count);
	while(scanf("%d", &n) == 1)
	{
		for(i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		for(i=0; i<n; i++)
		{
			for(j=0, max=-1; j<n; j++)
			{
				if((t=calc(i, j)) > max)
				{
					max = t;
					temp = j;
				}
			}
			printf(i?" %d":"%d", temp+1);
		}
		printf("\n");
	}
	return 0;
}

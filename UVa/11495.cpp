#include <stdio.h>

int tim;
int ary[100005], buf[100005];

void msort(int p, int q)
{
	int c, i, j, k;
	if(p >= q)
	{
		return;
	}
	c = ((p+q) >> 1);
	msort(p, c);
	msort(c+1, q);
	for(i=p, j=c+1, k=0; i<=c||j<=q; )
	{
		if(i <= c && (j > q || ary[i] < ary[j]))
		{
			buf[k] = ary[i];
			i++;
			k++;
		}
		else
		{
			tim += c-i+1;
			buf[k] = ary[j];
			j++;
			k++;
		}
	}
	for(i=0; i<k; i++)
	{
		ary[p+i] = buf[i];
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
		tim = 0;
		msort(0, n-1);
		if(tim % 2)
		{
			printf("Marcelo\n");
		}
		else
		{
			printf("Carlos\n");
		}
	}
	return 0;
}

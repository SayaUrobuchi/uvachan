#include <stdio.h>

int tbl[1100005];

int calc(int t)
{
	int temp, d;
	temp = t;
	while(temp > 1)
	{
		if(tbl[temp] == 0)
		{
			t = t / temp * (temp-1);
			break;
		}
		d = temp / tbl[temp];
		if(d % tbl[temp])
		{
			t = t / tbl[temp] * (tbl[temp]-1);
		}
		temp = d;
	}
	return t;
}

int main()
{
	int count, i, j, n, sum, scr;
	for(i=2; i<1100; i+=1+i%2)
	{
		if(tbl[i] == 0)
		{
			for(j=i*i; j<=1100000; j+=i)
			{
				tbl[j] = i;
			}
		}
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, sum=0; i<n; i++)
		{
			scanf("%d", &scr);
			sum += calc(scr);
		}
		printf("%.2lf\n", (double)sum/n);
	}
	return 0;
}

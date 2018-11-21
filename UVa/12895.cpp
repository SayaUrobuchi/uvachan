#include <stdio.h>

int ary[64];

int main()
{
	int n, t, d, i, j, sum, res, count;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		t = n;
		for (i=0; n; i++)
		{
			ary[i] = n%10;
			n /= 10;
		}
		d = i;
		sum = 0;
		for (i=0; i<d&&sum<=t; i++)
		{
			for (j=1, res=ary[i]; j<d; j++, res*=ary[i]);
			sum += res;
		}
		puts(sum==t?"Armstrong":"Not Armstrong");
	}
	return 0;
}

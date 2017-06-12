#include <stdio.h>
#include <math.h>

int main()
{
	int n, i, j, ans[21];
	double left, right;
	left = 0;
	right = log(2) * 4;
	for(i=1, j=0; j<21; i++)
	{
		left += log(i);
		if(left >= right)
		{
			right *= 2;
			ans[j++] = i - 1;
		}
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		n -= 1960;
		n /= 10;
		printf("%d\n", ans[n]);
	}
	return 0;
}

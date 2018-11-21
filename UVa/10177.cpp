#include <stdio.h>

char ans[101][150];

int main()
{
	int n, i;
	long long sum, d1, d2, d3, t1, t2, t3;
	sprintf(ans[0], "0 0 0 0 0 0");
	for(i=1, sum=0, d1=0, d3=0; i<=100; i++)
	{
		sum += i;
		d1 += i * i;
		d2 = sum * sum;
		d3 += i * i * i * i;
		t1 = d2;
		t2 = t1 * sum;
		t3 = t2 * sum;
		sprintf(ans[i], "%lld %lld %lld %lld %lld %lld", d1, t1-d1, d2, t2-d2, d3, t3-d3);
	}
	while(scanf("%d", &n) == 1)
	{
		printf("%s\n", ans[n]);
	}
	return 0;
}

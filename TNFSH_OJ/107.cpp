#include <stdio.h>

int main()
{
	int ans, sum, i;
	ans = 30;
	for (i=1, sum=0; i<=30; i++)
	{
		ans += i * (sum+=i);
	}
	ans += sum;
	printf("%d\n", ans);
	return 0;
}

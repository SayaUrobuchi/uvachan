#include <stdio.h>

int main()
{
	int n, tmp, ans[32];
	ans[0] = 0;
	ans[1] = 0;
	ans[2] = 0;
	ans[3] = 1;
	for(n=4, tmp=1; n<32; n++, tmp*=2)
	{
		ans[n] = ans[n-1] * 2;
		ans[n] += tmp;
		ans[n] -= ans[n-4];
	}
	while(scanf("%d", &n) == 1)
	{
		if(!n) break;
		printf("%d\n", ans[n]);
	}
	return 0;
}

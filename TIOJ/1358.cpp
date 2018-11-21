#include <stdio.h>

int main()
{
	int n, i, ans;
	while(scanf("%d", &n) == 1)
	{
		for(i=n-1, ans=0; i; ans+=i, i>>=1);
		printf("%d\n", ans);
	}
	return 0;
}

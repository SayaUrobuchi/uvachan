#include <stdio.h>
#include <math.h>

int main()
{
    int n, k, i;
    double ans;
    while(scanf("%d%d", &n, &k) == 2)
    {
		if(n-k < k)
		{
			k = n - k;
		}
		for(i = n - k + 1, ans=0; i<=n; i++)
		{
			ans += log10(i);
		}
		for(i=2; i<=k; i++)
		{
			ans -= log10(i);
		}
		printf("%d\n", (int)ans+1);
    }
    return 0;
}
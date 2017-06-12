#include <stdio.h>

int main()
{
	int ary[31], count, k, ans;
	char i, n, check;
	ary[1] = 1;
	for(i=2; i<31; i++) ary[i] = ary[i-1] * 2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &n, &k);
		ans = 0;
		check = 1;
		do
		{
			if(k < ary[n])
			{
				if(!check) ans += ary[n];
				check = 1;
			}
			else
			{
				if(check) ans += ary[n];
				k -= ary[n];
				check = 0;
			}
		}while(--n);
		printf("%d\n", ans);
	}
	return 0;
}

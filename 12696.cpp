#include <stdio.h>

#define N 4
#define LIM 12500

int ary[4];
int lim[] = {5600, 4500, 2500, 700};

int main()
{
	int count, res, ans, i, a, b;
	res = 0;
	scanf("%d", &count);
	while (count--)
	{
		ans = 1;
		for (i=0; i<N; i++)
		{
			scanf("%d.%d", &a, &b);
			ary[i] = a*100 + b;
			ans &= (ary[i]<=lim[i] ? 1 : 0);
			if (!ans && i == 2)
			{
				ans |= (ary[0]+ary[1]+ary[2] <= LIM ? 1 : 0);
			}
		}
		printf("%d\n", ans);
		res += ans;
	}
	printf("%d\n", res);
	return 0;
}

#include <iostream>

int main()
{
	int a, b, c, i, j, sum, ans;
	while (scanf("%d%d%d", &c, &a, &b) == 3)
	{
		for (i=4, j=i-c, sum=0, ans=0; sum<a+b; i++, j++)
		{
			sum += i;
			ans += i;
			if (j >= 3)
			{
				sum += j;
			}
			if (sum >= a+b)
			{
				break;
			}
		}
		printf("%d\n", a-ans);
	}
	return 0;
}

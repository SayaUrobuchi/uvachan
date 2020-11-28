#include <iostream>

int ary[1048576];

int main()
{
	int count, n, i, best, sum, ans;
	bool gg;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0, best=-1, sum=0, gg=false; i<n; i++)
		{
			scanf("%d", &ary[i]);
			sum += ary[i];
			if (ary[i] > best)
			{
				best = ary[i];
				ans = i;
				gg = false;
			}
			else if (ary[i] == best)
			{
				gg = true;
			}
		}
		if (gg)
		{
			puts("no winner");
		}
		else if ((best<<1) > sum)
		{
			printf("majority winner %d\n", ans+1);
		}
		else
		{
			printf("minority winner %d\n", ans+1);
		}
	}
	return 0;
}

#include <iostream>

int main()
{
	int n, i, t;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, t=-1; (1<<i)<n; i++)
		{
			if (t == -1 && (n & (1<<i)))
			{
				t = i;
			}
		}
		if (t == -1)
		{
			t = i;
		}
		printf("%d %d\n", 1<<i, i-t);
	}
	return 0;
}

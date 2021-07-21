#include <iostream>

int main()
{
	int n, i;
	double m, b, reward;
	while (scanf("%d%lf", &n, &m) == 2)
	{
		if (n == 0 && m == 0)
		{
			break;
		}
		for (i=0, reward=1; i<n; i++)
		{
			b = 1.0 / (reward*2);
			if (b < m)
			{
				b = m;
			}
			reward = (b-m)/(1-m) + (1-b)/(1-m) * (1+b) * reward;
		}
		printf("%.3lf\n", reward);
	}
	return 0;
}

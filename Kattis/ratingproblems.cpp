#include <iostream>

int main()
{
	int n, m, i, t, best, worst;
	while (scanf("%d%d", &n, &m) == 2)
	{
		for (i=0, best=(n-m)*3, worst=(n-m)*-3; i<m; i++)
		{
			scanf("%d", &t);
			best += t;
			worst += t;
		}
		printf("%.10f %.10f\n", worst*1.0/n, best*1.0/n);
	}
	return 0;
}

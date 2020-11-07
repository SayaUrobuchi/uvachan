#include <iostream>

int main()
{
	int n, i;
	double ans, fk;
	while (scanf("%d", &n) == 1)
	{
		for (i=0, fk=1, ans=0; i<=n&&fk>1e-18; i++, fk/=i)
		{
			ans += fk;
		}
		printf("%.16lf\n", ans);
	}
	return 0;
}

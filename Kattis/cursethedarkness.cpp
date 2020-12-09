#include <iostream>

int main()
{
	int count, n, i;
	double x, y, tx, ty;
	bool curse;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%lf%lf%d", &x, &y, &n);
		for (i=0, curse=true; i<n; i++)
		{
			scanf("%lf%lf", &tx, &ty);
			if ((tx-x)*(tx-x)+(ty-y)*(ty-y)<=64)
			{
				curse = false;
			}
		}
		puts(curse?"curse the darkness":"light a candle");
	}
	return 0;
}

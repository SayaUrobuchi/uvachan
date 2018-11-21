#include <stdio.h>

int main()
{
	int count, n, i, p, q, same, dif;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		same = 0;
		dif = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d%d", &p, &q);
			if(p == q)
			{
				same++;
			}
			else
			{
				dif++;
			}
		}
		// ee lose, eo lose, oe win, oo win
		if(!(same & 1))// == (dif & 1))
		{
			printf("dreamoon\n");
		}
		else
		{
			printf("kelvin\n");
		}
	}
	return 0;
}

#include <stdio.h>
#include <math.h>

int main()
{
	int i, j, f;
	double n, t;
	while(scanf("%lf", &n) == 1)
	{
		for(i=1, f=0; ; i++)
		{
			t = n * (pow(3, i)-1);
			if(t >= pow(3, i)*3)
			{
				break;
			}
			for(j=i; t>0+1e-8; j--)
			{
				if(t / pow(3, j) >= 1.0 && t/pow(3, j) < 2.0)
				{
					break;
				}
			}
			if(t <= 0+1e-8)
			{
				f = 1;
				break;
			}
		}
		if(f)
		{
			printf("MEMBER\n");
		}
		else
		{
			printf("NON-MEMBER\n");
		}
	}
	return 0;
}

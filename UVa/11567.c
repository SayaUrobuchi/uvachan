#include <stdio.h>

int main()
{
	unsigned int s;
	int i, j, k, l;
	while(scanf("%u", &s) == 1)
	{
		for(i=0, j=31, k=0, l=0; j>=0; j--)
		{
			if(s >= (1u<<j))
			{
				l = 1;
				s -= (1u<<j);
				k++;
				if(k <= 2)
				{
					i++;
				}
			}
			else
			{
				k = 0;
			}
			i += l;
		}
		printf("%d\n", i);
	}
	return 0;
}


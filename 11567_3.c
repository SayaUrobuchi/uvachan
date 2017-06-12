#include <stdio.h>

int main()
{
	unsigned int s;
	int i, j, k, l, f, p, q, r;
	while(scanf("%u", &s) == 1)
	{
		for(i=0, j=31, k=0, l=0, p=q=0, f=0, r=0; j>=0; j--)
		{
			/*printf("%d", s&(1u<<j)?1:0);*/
			i += l;
			if(s >= (1u<<j))
			{
				if(k == 1)
				{
					q = p;
					p = 0;
				}
				l = 1;
				s -= (1u<<j);
				k++;
				if(k == 1)
				{
					i++;
				}
				else if(k == 2)
				{
					i++;
					if(r > 1 && f && q == 1)
					{
						i--;
					}
				}
				else if(f == 0 && k == 3)
				{
					i++;
				}
			}
			else
			{
				r = k;
				k = 0;
				f = l;
				p++;
			}
		}
		/*printf("\n");*/
		printf("%d\n", i);
	}
	return 0;
}


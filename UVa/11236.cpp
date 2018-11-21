#include <stdio.h>

int main()
{
	int n, i, j, k, ij, ijk, ijp, ijkp, res, c=0;
	for(i=2; i<212; i++)
	{
		for(j=i; j<1180; j++)
		{
			ij = i * j;
			if(ij > 44722)
			{
				break;
			}
			ijp = i + j;
			if(ijp > 1000)
			{
				break;
			}
			for(k=j; k<2000; k++)
			{
				ijk = ij * k;
				if(k > 2000000000 / ijk)
				{
					break;
				}
				ijkp = ijp + k;
				if(k > 2000 - ijkp)
				{
					break;
				}
				ijkp *= 1000000;
				if(ijk > 1000000 && !(ijkp % (ijk-1000000)))
				{
					res = ijkp / (ijk-1000000);
					if(res + ijkp / 1000000 <= 2000 && res >= k)
					{
						printf("%d.%02d %d.%02d %d.%02d %d.%02d\n", i/100, i%100, j/100, j%100, k/100, k%100, res/100, res%100);
					}
				}
			}
			if(k == j)
			{
				break;
			}
		}
		if(j == i)
		{
			break;
		}
	}
	return 0;
}

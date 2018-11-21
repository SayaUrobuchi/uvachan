#include <stdio.h>
#include "1360_soldier.h"

int main()
{
	int n, m, i, j, k, l, temp;
	WarCraft();
	n = Find_n();
	m = Find_m();
	for(i=0, l=0; i<n; i++)
	{
		for(j=l, k=0; j<m-n+i+1; j++)
		{
			if((temp=Hey_Man(i, j)) > k)
			{
				k = temp;
				l = j + 1;
			}
		}
		Report(k);
	}
	return 0;
}

#include <stdio.h>
#include <math.h>
#include <1359_lost.h>

int ary1[2000000], ary2[2000000], ary3[2000000];

int main()
{
	int n, m, i, j, k, p, q, r, *a1, *a2, *a3, ans, *temp;
	n = Initialize();
	m = log2(n-1)+1e-10;
	for(i=0; i<n-1; i++)
	{
		ary3[i] = i+1;
	}
	for(i=0, j=1, a1=ary1, a2=ary2, a3=ary3, r=n-1, ans=0; i<=m; i++, j<<=1)
	{
		p = q = 0;
		for(k=0; k<r; k++)
		{
			if(Ask(a3[k], i+1))
			{
				a2[q++] = a3[k];
			}
			else
			{
				a1[p++] = a3[k];
			}
		}
		if(p <= q)
		{
			temp = a3;
			a3 = a1;
			a1 = temp;
			r = p;
		}
		else
		{
			temp = a3;
			a3 = a2;
			a2 = temp;
			r = q;
			ans += j;
		}
	}
	Answer(ans);
	return 0;
}

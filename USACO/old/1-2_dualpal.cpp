/*
ID: sa072682
LANG: C
TASK: dualpal
*/
#include <stdio.h>

int main()
{
	int n, s, i, j, k, l, p, q;
	char buf[100];
	freopen("dualpal.in", "r", stdin);
	freopen("dualpal.out", "w", stdout);
	scanf("%d%d", &n, &s);
	for(s++; ; s++)
	{
		for(i=2, j=0; i<11; i++)
		{
			k = s;
			l = 0;
			while(k)
			{
				buf[l++] = k % i;
				k /= i;
			}
			for(p=0, q=l-1; p<q; p++, q--)
			{
				if(buf[p] != buf[q])
				{
					break;
				}
			}
			if(p >= q)
			{
				if(j)
				{
					break;
				}
				j++;
			}
		}
		if(i < 11)
		{
			printf("%d\n", s);
			n--;
			if(!n)
			{
				break;
			}
		}
	}
	return 0;
}

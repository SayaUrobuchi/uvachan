#include <stdio.h>
#include <string.h>

int c[10005];

int main()
{
	int n, i, j, s, f, a, t;
	while(scanf("%d", &n) == 1)
	{
		if(!n)
		{
			break;
		}
		memset(c, 0, sizeof(c));
		s = 0;
		f = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &a);
			if(a < n)
			{
				c[a]++;
			}
			else
			{
				f = 1;
			}
			s += a;
		}
		if(f || (s & 1))
		{
			printf("Not possible\n");
			continue;
		}
		for(i=n-1; i>0; )
		{
			if(c[i] == 0)
			{
				i--;
				continue;
			}
			c[i]--;
			for(j=i, t=0; j>0; j--)
			{
				t += c[j];
				if(t >= i)
				{
					break;
				}
			}
			if(j == 0)
			{
				break;
			}
			c[j-1] += i-(t-c[j]);
			c[j] -= i-(t-c[j]);
			for(j++; j<=i; j++)
			{
				c[j-1] += c[j];
				c[j] = 0;
			}
		}
		if(i > 0)
		{
			printf("Not possible\n");
		}
		else
		{
			printf("Possible\n");
		}
	}
	return 0;
}

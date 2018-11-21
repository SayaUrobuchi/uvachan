#include <stdio.h>

int pairi[1000000], pairc[1000000];
char str[1000000], s[1000000];

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int n, i, c, ans;
	n = 0;
	while(gets(str))
	{
		if(sscanf(str, "%d%s", &pairi[n], s) == 2)
		{
			if(pairi[n])
			{
				sscanf(s, "%d", &pairc[n]);
			}
			n++;
		}
		else
		{
			for(i=n-1, ans=0, c=0; i>-1; i--)
			{
				if(pairi[i])
				{
					ans = min(ans+pairc[i], -pairi[i]);
				}
				else
				{
					c += (++ans >= 0 && i);
				}
			}
			n = 0;
			printf("%d\n", c);
		}
	}
	return 0;
}

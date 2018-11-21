#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int f[1050], used[1050];

int comp(const void *p, const void *q)
{
	return *(int*)q - *(int*)p;
}

int ab(int p)
{
	return p < 0 ? -p : p;
}

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int count, n, m, i, j, k, s, r, temp, dsp, csp, wsp, ans, open, on;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d", &dsp, &csp, &wsp);
		scanf("%d%d", &n, &m);
		for(i=0; i<m; i++)
		{
			scanf("%d", &f[i]);
		}
		if(m == 0)
		{
			printf("0\n");
			continue;
		}
		qsort(f, m, sizeof(int), comp);
		memset(used, 0, sizeof(used));
		if(wsp <= dsp || dsp*n+csp > wsp*f[0])
		{
			printf("%d\n", f[0]*wsp);
			continue;
		}
		for(i=0, s=n, ans=0; i<m; i=j+1)
		{
			if(ans+dsp*s+csp > wsp*f[i])
			{
				ans += dsp*s;
				break;
			}
			for(j=i+1; j<m; j++)
			{
				if(ans+dsp*s+csp >= wsp*f[j])
				{
					break;
				}
				for(k=0; k<=s; k++)
				{
					if(ans+dsp*(s-k)+(j-i+1)*csp >= max(wsp*ab(k-f[j]), max(dsp*(s-k)+ans, wsp*ab(k-f[i]))) + csp)
					{
						printf("lala %d %d\n", j, k);
						printf("lalala %d %d\n", ans+dsp*(s-k)+(j-i+1)*csp, max(wsp*ab(k-f[j]), max(dsp*(s-k)+ans, wsp*ab(k-f[i]))) + csp);
						break;
					}
				}
				if(k > s)
				{
					break;
				}
			}
			printf("J %d\n", j);
			for(k=0, j--, temp=2147483647; k<=s; k++)
			{
				if(temp > max(max(wsp*ab(k-f[j])-ans, 0), max(dsp*(s-k), max(0, wsp*ab(k-f[i])-ans))) + csp)
				{
					temp = max(max(wsp*ab(k-f[j])-ans, 0), max(dsp*(s-k), max(0, wsp*ab(k-f[i])-ans))) + csp;
					r = k;
				}
			}
			ans += temp;
			printf("ANS %d\n", ans);
			s = r;
			printf("S %d\n", s);
		}
		printf("%d\n", ans);
	}
	return 0;
}

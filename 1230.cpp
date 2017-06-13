#include <stdio.h>

int main()
{
	int count, n, m, o, i, t, r;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d%d", &n, &m, &o);
		for (i=0, t=n, r=1; i<=30; i++, t=(t*t)%o)
		{
			if (m & (1<<i))
			{
				r = (r*t) % o;
			}
		}
		printf("%d\n", r);
	}
	return 0;
}

#include <iostream>

int main()
{
	int a, b, c, d, i, j, k, ans;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		for (i=0, ans=0; i<=d; i+=a)
		{
			for (j=0; i+j<=d; j+=b)
			{
				if ((d-i-j)%c == 0)
				{
					printf("%d %d %d\n", i/a, j/b, (d-i-j)/c);
					++ans;
				}
			}
		}
		if (!ans)
		{
			puts("impossible");
		}
	}
	return 0;
}

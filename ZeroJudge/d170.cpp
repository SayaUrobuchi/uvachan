#include <stdio.h>

int min(int p, int q)
{
	return p<q ? p : q;
}

int max(int p, int q)
{
	return p>q ? p : q;
}

int main()
{
	int count, a, b, c, d, e, f;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
		if((c-a)*(f-b) == (d-b)*(e-a) && e >= min(a, c) && e <= max(a, c) && f >= min(b, d) && f <= max(b, d))
		{
			printf("該死的東西!竟敢想讓我死！\n");
		}
		else
		{
			printf("父親大人!母親大人!我快到了！\n");
		}
	}
	return 0;
}

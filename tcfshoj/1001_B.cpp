#include <stdio.h>

int ab(int a)
{
	return a<0?-a:a;
}

int main()
{
	int count, n, m, i, l, r, *p, *q, o, *t;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		l = 1;
		r = -m;
		p = &l;
		q = &r;
		for(i=0; i<n; i++)
		{
			scanf("%d", &o);
			printf("%d", ab((*p)++));
			while(o--)
			{
				printf(" %d", ab((*q)++));
			}
			printf("\n");
			t = p;
			p = q;
			q = t;
		}
	}
	return 0;
}

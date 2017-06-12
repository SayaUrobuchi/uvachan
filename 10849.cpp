#include <stdio.h>

int ab(int now)
{
	if(now < 0)
	{
		return -now;
	}
	return now;
}

int main()
{
	int count, n, m, p, q, x1, x2, y1, y2;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &m, &n);
		while(m--)
		{
			scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
			if(x1 == x2 && y1 == y2)
			{
				printf("0\n");
			}
			else if((p=ab(x1-x2))%2 == (q=ab(y1-y2))%2)
			{
				if(p == q)
				{
					printf("1\n");
				}
				else
				{
					printf("2\n");
				}
			}
			else
			{
				printf("no move\n");
			}
		}
	}
	return 0;
}

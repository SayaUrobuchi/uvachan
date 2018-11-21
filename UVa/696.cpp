#include <stdio.h>

int main()
{
	int n, m, temp;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(!n && !m)
		{
			break;
		}
		if(!n || !m)
		{
			printf("0 knights may be placed on a %d row %d column board.\n", n, m);
		}
		else if(n == 1)
		{
			printf("%d knights may be placed on a %d row %d column board.\n", m, n, m);
		}
		else if(m == 1)
		{
			printf("%d knights may be placed on a %d row %d column board.\n", n, n, m);
		}
		else if(n == 2)
		{
			temp = m - m % 4;
			if(m % 4 >= 2)
			{
				temp += 4;
			}
			else if(m % 4 == 1)
			{
				temp += 2;
			}
			printf("%d knights may be placed on a %d row %d column board.\n", temp, n, m);
		}
		else if(m == 2)
		{
			temp = n - n % 4;
			if(n % 4 >= 2)
			{
				temp += 4;
			}
			else if(n % 4 == 1)
			{
				temp += 2;
			}
			printf("%d knights may be placed on a %d row %d column board.\n", temp, n, m);
		}
		else
		{
			printf("%d knights may be placed on a %d row %d column board.\n", (n*m+1)/2, n, m);
		}
	}
	return 0;
}

#include <stdio.h>

int main()
{
	int n, m;
	while (scanf("%d%d", &n, &m) == 2)
	{
		if (n > m)
		{
			printf("Dr. Chaz needs %d more piece%s of chicken!\n", n-m, n-m==1?"":"s");
		}
		else
		{
			printf("Dr. Chaz will have %d piece%s of chicken left over!\n", m-n, m-n==1?"":"s");
		}
	}
	return 0;
}

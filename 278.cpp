#include <stdio.h>

int main()
{
	int count, n, m;
	char buf[2];
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%d%d", buf, &n, &m);
		if(buf[0] == 'r' || buf[0] == 'Q')
		{
			printf("%d\n", n < m ? n : m);
		}
		else if(buf[0] == 'k')
		{
			printf("%d\n", (n * m + 1) / 2);
		}
		else
		{
			printf("%d\n", ((n + 1)/2) * ((m + 1)/2));
		}
	}
	return 0;
}
#include <stdio.h>

int main()
{
	int n, m, i;
	char str[2000];
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0; i<n; i++)
		{
			scanf("%s", str);
			if(i == n - m)
			{
				printf("%s\n", str);
			}
		}
	}
	return 0;
}

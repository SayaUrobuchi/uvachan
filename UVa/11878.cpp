#include <stdio.h>
#include <stdlib.h>

char s[105], op;

int main()
{
	int ans, n1, n2;
	ans = 0;
	while(scanf("%d%c%d=%s", &n1, &op, &n2, s) == 4)
	{
		if(*s != '?')
		{
			if(op == '-')
			{
				n2 = -n2;
			}
			ans += (atoi(s)==n1+n2);
		}
	}
	printf("%d\n", ans);
	return 0;
}

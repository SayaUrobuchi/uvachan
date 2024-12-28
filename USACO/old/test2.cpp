/*
ID: sa072682
LANG: C
TASK: test
*/

#include <stdio.h>

int main()
{
	int i, j;
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	while(scanf("%d%d", &i, &j) == 2)
	{
		printf("%d\n", i + j);
	}
	return 0;
}

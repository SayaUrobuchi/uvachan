#include <iostream>

int main()
{
	int cas, count, n, m;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		printf("Case #%d: %s\n", ++cas, (m&((1<<n)-1))==((1<<n)-1)?"ON":"OFF");
	}
	return 0;
}

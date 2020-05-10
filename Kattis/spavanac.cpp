#include <stdio.h>

int main()
{
	int p, q, t;
	while (scanf("%d%d", &p, &q) == 2)
	{
		t = p*60 + q;
		t = (t+1440-45) % 1440;
		printf("%d %d\n", t/60, t%60);
	}
	return 0;
}

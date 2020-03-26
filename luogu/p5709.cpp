#include <stdio.h>
#include <algorithm>

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	printf("%d\n", std::max(0, a-((c-1)/b+1)));
	return 0;
}

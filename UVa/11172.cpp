#include <stdio.h>

int main()
{
	int count, i, j;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d%d", &i, &j);
		if(i > j) printf(">\n");
		else if(i == j) printf("=\n");
		else printf("<\n");
	}
	return 0;
}

#include <stdio.h>

char s0[1048576], s1[1048576];

int main()
{
	int y, m, d;
	scanf("%d%d%d%s%s", &y, &m, &d, s0, s1);
	printf("%d/%d/%d\nDoodle Name: %s\nReviews: %s\n", y+1997, m, d, s0, s1);
	return 0;
}

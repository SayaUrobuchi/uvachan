#include <iostream>

char s0[1024], s1[1024], s2[1024];

int main()
{
	int t, sh, sm, eh, em;
	while (scanf("%s%s%s%d:%d%d:%d", s0, s1, s2, &sh, &sm, &eh, &em) == 7)
	{
		t = (eh*60+em) - (sh*60+sm);
		printf("%s %s %s %d hours %d minutes\n", s0, s1, s2, t/60, t%60);
	}
	return 0;
}

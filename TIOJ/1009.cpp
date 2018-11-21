#include <stdio.h>

int main()
{
	int h, m, s, h2, m2, s2, t, t2;
	while(scanf("%d:%d:%d%d:%d:%d", &h, &m, &s, &h2, &m2, &s2) == 6)
	{
		t = h * 3600 + m * 60 + s;
		t2 = h2 * 3600 + m2 * 60 + s2;
		if(t2 < t)
		{
			t2 += 24 * 3600;
		}
		t2 -= t;
		printf("%02d:%02d:%02d\n", t2/3600, (t2%3600)/60, t2%60);
	}
	return 0;
}

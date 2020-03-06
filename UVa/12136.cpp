#include <stdio.h>

int main()
{
	int count, cas, p, q, r, s, s0, e0, s1, e1;
	cas = 0;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d:%d%d:%d", &p, &q, &r, &s);
		s0 = p*60+q;
		e0 = r*60+s;
		scanf("%d:%d%d:%d", &p, &q, &r, &s);
		s1 = p*60+q;
		e1 = r*60+s;
		printf("Case %d: %s Meeting\n", ++cas, (s0 <= e1 && s1 <= e0) ? "Mrs" : "Hits");
	}
	return 0;
}

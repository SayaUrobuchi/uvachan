#include <iostream>

int main()
{
	int p, q, r, s, a, b, c, d, cas;
	cas = 0;
	while (scanf("%d%d%d%d", &p, &q, &r, &s) == 4)
	{
		// [p q]   [a b]   [1 0]
		// [r s] X [c d] = [0 1]
		// pa + qc = 1
		// pb + qd = 0
		// ra + sc = 0
		// rb + sd = 1
		// ====
		// qra + qsc = 0
		// spa + sqc = s
		a = s / (s*p - q*r);
		c = (q ? (1-p*a) / q : -r*a / s);
		// ====
		// qrb + qsd = q
		// spb + sqd = 0
		b = q / (q*r - s*p);
		d = (q ? -p*b / q : (1-r*b) / s);
		++cas;
		printf("Case %d:\n", cas);
		printf("%d %d\n%d %d\n", a, b, c, d);
	}
	return 0;
}

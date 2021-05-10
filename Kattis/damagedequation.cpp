#include <iostream>

const int MUL = 0;
const int ADD = 1;
const int SUB = 2;
const int DIV = 3;

const char *tbl = "*+-/";

int calc(int a, int b, int op)
{
	if (op == ADD)
	{
		return a+b;
	}
	if (op == SUB)
	{
		return a-b;
	}
	if (op == MUL)
	{
		return a*b;
	}
	return a/b;
}

int main()
{
	int a, b, c, d, i, p, q, r, s, ans;
	while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4)
	{
		for (i=0, ans=0; i<16; i++)
		{
			p = (i >> 2);
			q = (i & 3);
			if ((p == DIV && b == 0) || (q == DIV && d == 0))
			{
				continue;
			}
			r = calc(a, b, p);
			s = calc(c, d, q);
			if (r == s)
			{
				printf("%d %c %d = %d %c %d\n", a, tbl[p], b, c, tbl[q], d);
				++ans;
			}
		}
		if (!ans)
		{
			puts("problems ahead");
		}
	}
	return 0;
}

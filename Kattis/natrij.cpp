#include <iostream>

int main()
{
	int a, b, c, d, e, f, st, ed, diff;
	while (scanf("%d:%d:%d", &a, &b, &c) == 3)
	{
		scanf("%d:%d:%d", &d, &e, &f);
		st = a*3600 + b*60 + c;
		ed = d*3600 + e*60 + f;
		if (ed <= st)
		{
			ed += 24*3600;
		}
		diff = (ed - st);
		printf("%02d:%02d:%02d\n", diff/3600, diff/60%60, diff%60);
	}
	return 0;
}

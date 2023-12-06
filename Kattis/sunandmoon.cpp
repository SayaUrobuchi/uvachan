#include <iostream>
using namespace std;

int main()
{
	int p, q, at, as, bt, bs;
	scanf("%d%d", &as, &at);
	scanf("%d%d", &bs, &bt);
	for (p=at-as, q=bt-bs; p!=q; )
	{
		if (p < q)
		{
			p += at;
		}
		else
		{
			q += bt;
		}
	}
	printf("%d\n", p);
	return 0;
}

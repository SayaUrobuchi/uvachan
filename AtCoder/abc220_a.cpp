#include <iostream>
using namespace std;

int main()
{
	int a, b, c, t;
	while (scanf("%d%d%d", &a, &b, &c) == 3)
	{
		t = ((a-1)/c+1)*c;
		printf("%d\n", t>b?-1:t);
	}
	return 0;
}


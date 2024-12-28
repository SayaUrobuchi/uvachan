#include <iostream>
using namespace std;

int main()
{
	int a, b;
	char op;
	scanf("%d %c%d", &a, &op, &b);
	int ans = a + b;
	if (op == '-')
	{
		ans = a - b;
	}
	printf("%d\n", ans);
	return 0;
}

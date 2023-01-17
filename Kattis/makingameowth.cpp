#include <iostream>
using namespace std;

int main()
{
	int a, b, c, d, turn;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	turn = b / (a-1);
	printf("%d\n", c*b+d*turn);
	return 0;
}

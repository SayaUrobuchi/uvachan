#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int a, b, c;
	scanf("%d%d%d%s", &a, &b, &c, s);
	printf("%d %s\n", a+b+c, s);
	return 0;
}

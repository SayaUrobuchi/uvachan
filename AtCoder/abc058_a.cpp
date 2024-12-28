#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	puts(c-b==b-a ? "YES" : "NO");
	return 0;
}

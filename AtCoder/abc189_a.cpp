#include <iostream>
using namespace std;

int main()
{
	char a, b, c;
	scanf("%c%c%c", &a, &b, &c);
	puts(a == b && a == c ? "Won" : "Lost");
	return 0;
}

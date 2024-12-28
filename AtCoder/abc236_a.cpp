#include <iostream>
using namespace std;

int main()
{
	int a, b;
	char s[16];
	scanf("%s", s);
	scanf("%d%d", &a, &b);
	swap(s[a-1], s[b-1]);
	puts(s);
	return 0;
}

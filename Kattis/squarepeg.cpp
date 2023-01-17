#include <iostream>
using namespace std;

int main()
{
	int l, r;
	scanf("%d%d", &l, &r);
	puts(l*l<2*r*r?"fits":"nope");
	return 0;
}

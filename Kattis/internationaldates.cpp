#include <iostream>
using namespace std;

const int US = 1;
const int EU = 2;

const char *nam[] = {"", "US", "EU", "either"};

int main()
{
	int a, b;
	scanf("%d/%d/%*d", &a, &b);
	int typ = 0;
	if (a <= 12 && b <= 31)
	{
		typ |= US;
	}
	if (a <= 31 && b <= 12)
	{
		typ |= EU;
	}
	puts(nam[typ]);
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%*d%d%d", &a, &b);
	if ((b-a) & 1)
	{
		puts("Borys");
	}
	else
	{
		puts("Alice");
	}
	return 0;
}
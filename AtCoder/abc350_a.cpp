#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("ABC%d", &n);
	if (n >= 1 && n <= 349 && n != 316)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}

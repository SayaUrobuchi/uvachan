#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	int a = 0;
	int b = 0;
	while (a < n || b < n+1)
	{
		if (a == b)
		{
			putchar('1');
			++b;
		}
		else
		{
			putchar('0');
			++a;
		}
	}
	puts("");
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<=n; i++)
	{
		putchar(i%3 ? 'o' : 'x');
	}
	puts("");
	return 0;
}

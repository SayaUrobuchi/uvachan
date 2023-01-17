#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if ((a*b-1) & 1)
	{
		puts("Alf");
	}
	else
	{
		puts("Beata");
	}
	return 0;
}

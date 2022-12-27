#include <iostream>
using namespace std;

int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	if (n%500 > m)
	{
		puts("No");
	}
	else
	{
		puts("Yes");
	}
	return 0;
}
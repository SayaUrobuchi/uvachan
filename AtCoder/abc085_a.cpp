#include <iostream>
using namespace std;

int main()
{
	int m, d;
	scanf("%*d/%d/%d", &m, &d);
	printf("%d/%02d/%02d\n", 2018, m, d);
	return 0;
}
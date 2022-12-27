#include <iostream>
using namespace std;

int main()
{
	int rat;
	scanf("%d", &rat);
	printf("%.10lf\n%.10lf\n", 100./rat, 100./(100-rat));
	return 0;
}
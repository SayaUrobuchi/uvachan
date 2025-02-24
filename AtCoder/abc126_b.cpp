#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%2d%2d", &a, &b);
	bool yymm = (b >= 1 && b <= 12);
	bool mmyy = (a >= 1 && a <= 12);
	if (yymm && mmyy)
	{
		puts("AMBIGUOUS");
	}
	else if (yymm)
	{
		puts("YYMM");
	}
	else if (mmyy)
	{
		puts("MMYY");
	}
	else
	{
		puts("NA");
	}
	return 0;
}

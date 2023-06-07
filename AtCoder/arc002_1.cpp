#include <iostream>
using namespace std;

int main()
{
	int year;
	scanf("%d", &year);
	bool leap = (year % 400 == 0 || (year % 4 == 0 && year % 100));
	puts(leap ? "YES" : "NO");
	return 0;
}

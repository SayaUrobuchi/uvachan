#include <iostream>
using namespace std;

int main()
{
	int a, b, c, da, db;
	scanf("%d%d%d", &a, &b, &c);
	da = b-a;
	db = c-b;
	if (da * db < 0)
	{
		puts("turned");
	}
	else if (da == db)
	{
		puts("cruised");
	}
	else if (abs(da) < abs(db))
	{
		puts("accelerated");
	}
	else
	{
		puts("braked");
	}
	return 0;
}

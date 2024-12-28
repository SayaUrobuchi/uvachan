#include <iostream>
using namespace std;

int tbl[16];

int main()
{
	int a, b;
	tbl[4] = 1;
	tbl[6] = 1;
	tbl[9] = 1;
	tbl[11] = 1;
	tbl[2] = 2;
	scanf("%d%d", &a, &b);
	puts(tbl[a] == tbl[b] ? "Yes" : "No");
	return 0;
}

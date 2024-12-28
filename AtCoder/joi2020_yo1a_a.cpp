#include <iostream>
using namespace std;

int main()
{
	int i;
	int tbl[4] = {};
	for (i=0; i<3; i++)
	{
		int t;
		scanf("%d", &t);
		++tbl[t];
	}
	puts(tbl[1]>tbl[2] ? "1" : "2");
	return 0;
}

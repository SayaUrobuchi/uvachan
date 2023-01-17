#include <iostream>
using namespace std;

const char* ctbl = "FEDCBA";

int ary[6];

int main()
{
	int i, t;
	for (i=4; i>=0; i--)
	{
		scanf("%d", &ary[i]);
	}
	scanf("%d", &t);
	for (i=0; i<5&&t>=ary[i]; i++);
	printf("%c\n", ctbl[i]);
	return 0;
}

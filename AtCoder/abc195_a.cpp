#include <iostream>
using namespace std;

int main()
{
	int m, h;
	scanf("%d%d", &m, &h);
	puts(h%m ? "No" : "Yes");
	return 0;
}

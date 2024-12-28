#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	puts(!(n&1)&&n>2 ? "YES" : "NO");
	return 0;
}

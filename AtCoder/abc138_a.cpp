#include <iostream>
using namespace std;

char s[16];

int main()
{
	int n;
	scanf("%d%s", &n, s);
	puts(n>=3200 ? s : "red");
	return 0;
}

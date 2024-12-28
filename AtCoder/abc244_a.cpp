#include <iostream>
using namespace std;

int main()
{
	int n;
	char s[1024];
	scanf("%d%s", &n, s);
	printf("%c\n", s[n-1]);
	return 0;
}

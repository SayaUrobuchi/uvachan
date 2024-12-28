#include <iostream>
using namespace std;

int main()
{
	char c;
	scanf("%c", &c);
	char ans = 'A';
	if (c >= 'a' && c <= 'z')
	{
		ans = 'a';
	}
	printf("%c\n", ans);
	return 0;
}

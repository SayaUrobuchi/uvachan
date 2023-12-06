#include <iostream>
using namespace std;

bool vow[128];

int main()
{
	char c;
	vow['A'] = vow['E'] = vow['I'] = vow['O'] = vow['U'] = true;
	scanf("%c", &c);
	if (c == 'Y')
	{
		puts("Kannski");
	}
	else if (vow[c])
	{
		puts("Jebb");
	}
	else
	{
		puts("Neibb");
	}
	return 0;
}

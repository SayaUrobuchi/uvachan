#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	string s(n, '0'+n);
	puts(s.c_str());
	return 0;
}

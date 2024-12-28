#include <iostream>
using namespace std;

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	puts(a.back() == b[0] && b.back() == c[0] ? "YES" : "NO");
	return 0;
}

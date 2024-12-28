#include <iostream>
using namespace std;

int main()
{
	string a, b, c;
	cin >> a >> b >> c;
	string ans;
	ans += a[0] ^ 32;
	ans += b[0] ^ 32;
	ans += c[0] ^ 32;
	puts(ans.c_str());
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	int t = min(a, b);
	string ans(max(a, b), '0'+t);
	puts(ans.c_str());
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int n0, n1;
	string s0, s1, pat;
	cin >> s0 >> s1;
	cin >> n0 >> n1;
	cin >> pat;
	if (s0 == pat)
	{
		--n0;
	}
	else
	{
		--n1;
	}
	printf("%d %d\n", n0, n1);
	return 0;
}

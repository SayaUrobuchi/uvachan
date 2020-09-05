#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	while (cin >> a >> b >> c)
	{
		if (a == 0 && b == 0 && c == 0)
		{
			break;
		}
		cout << (a*a+b*b==c*c || a*a+c*c==b*b || b*b+c*c==a*a ? "right" : "wrong") << "\n";
	}
	return 0;
}

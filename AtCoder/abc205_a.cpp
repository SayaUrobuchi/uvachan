#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	int a, b;
	while (cin >> a >> b)
	{
		cout << fixed << setprecision(10) << a*b/100.0 << "\n";
	}
	return 0;
}

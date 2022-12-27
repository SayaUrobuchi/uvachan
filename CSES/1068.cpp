#include <iostream>
using namespace std;

int main()
{
	long long n;
	while (cin >> n)
	{
		while (n > 1)
		{
			cout << n << " ";
			if (n & 1)
			{
				n = n*3 + 1;
			}
			else
			{
				n >>= 1;
			}
		}
		cout << "1\n";
	}
	return 0;
}

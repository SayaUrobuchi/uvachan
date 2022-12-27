#include <iostream>
using namespace std;

int main()
{
	int n, i;
	while (cin >> n)
	{
		if (n == 2 || n == 3)
		{
			cout << "NO SOLUTION\n";
		}
		else
		{
			for (i=2; i<=n; i+=2)
			{
				cout << i << " ";
			}
			cout << 1;
			for (i=3; i<=n; i+=2)
			{
				cout << " " << i;
			}
			cout << "\n";
		}
	}
	return 0;
}


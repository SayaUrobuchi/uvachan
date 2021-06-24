#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	while (cin >> n)
	{
		for (i=0, j=0; !i||j; i++)
		{
			j = (j*10+1) % n;
		}
		cout << i << "\n";
	}
	return 0;
}

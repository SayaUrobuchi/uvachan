#include <iostream>
using namespace std;

int main()
{
	int n, t;
	while (cin >> n)
	{
		t = n * 1.08;
		if (t < 206)
		{
			cout << "Yay!\n";
		}
		else if (t == 206)
		{
			cout << "so-so\n";
		}
		else
		{
			cout << ":(\n";
		}
	}
	return 0;
}

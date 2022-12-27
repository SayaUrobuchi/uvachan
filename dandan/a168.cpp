#include <iostream>
#include <vector>
using namespace std;

string v[1000000];

int main()
{
	int n, i;
	cin >> n;
	for (i=0; i<n; i++)
	{
		cin >> v[i];
	}
	cin >> i;
	cout << v[i-1] << "\n";
	return 0;
}
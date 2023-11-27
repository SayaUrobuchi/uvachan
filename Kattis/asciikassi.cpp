#include <iostream>
#include <iomanip>
using namespace std;

void out(char lr, char md, int cnt)
{
	cout << lr << setw(cnt) << setfill(md) << "" << lr << "\n";
}

int main()
{
	int n, i;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	out('+', '-', n);
	for (i=0; i<n; i++)
	{
		out('|', ' ', n);
	}
	out('+', '-', n);
	return 0;
}

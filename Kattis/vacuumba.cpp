#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const double PI = acos(-1);

int main()
{
	int count, n, i;
	double ang, x, y, a, b;
	cin >> count;
	while (count--)
	{
		cin >> n;
		for (i=0, ang=90, x=0, y=0; i<n; i++)
		{
			cin >> a >> b;
			ang += a;
			x += cos(ang*PI/180) * b;
			y += sin(ang*PI/180) * b;
		}
		cout << fixed << setprecision(6) << x << " " << y << "\n";
	}
	return 0;
}

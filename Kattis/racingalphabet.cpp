#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

const int M = 28;
const int M2 = (M>>1);
const double PI = acos(-1);

int pos[128];
string ts = "ABCDEFGHIJKLMNOPQRSTUVWXYZ '";

int main()
{
	int n, i, j, last, sum, t, u;
	for (i=0; i<ts.size(); i++)
	{
		pos[ts[i]] = i;
	}
	string s;
	while (cin >> n)
	{
		getline(cin, s);
		for (i=0; i<n; i++)
		{
			getline(cin, s);
			for (j=1, last=pos[s[0]], sum=0; j<s.size(); last=t, j++)
			{
				t = pos[s[j]];
				u = (t-last+M) % M;
				if (u > M2)
				{
					u = M - u;
				}
				sum += u;
			}
			cout << fixed << setprecision(10) << sum/(double)M*60*PI/15+s.size() << "\n";
		}
	}
}

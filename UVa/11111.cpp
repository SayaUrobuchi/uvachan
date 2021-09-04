#include <iostream>
#include <sstream>
using namespace std;

struct doll
{
	int siz, remain;
};

int sn;
doll stk[1048576];

int main()
{
	int t;
	bool gg;
	string s;
	while (getline(cin, s))
	{
		stringstream ss(s);
		sn = 0;
		gg = false;
		while (!gg && (ss >> t))
		{
			if (t > 0)
			{
				if (!sn || t != stk[sn-1].siz)
				{
					gg = true;
				}
				else
				{
					--sn;
				}
			}
			else
			{
				t = -t;
				if (!sn || stk[sn-1].remain > t)
				{
					stk[sn].remain = stk[sn].siz = t;
					if (sn)
					{
						stk[sn-1].remain -= t;
					}
					++sn;
				}
				else
				{
					gg = true;
				}
			}
		}
		cout << (gg||sn?":-( Try again.":":-) Matrioshka!") << "\n";
	}
	return 0;
}


#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int i, total, ans;
	string buf, s;
	while (getline(cin, buf))
	{
		stringstream ss(buf);
		total = 0;
		ans = 0;
		while (ss >> s)
		{
			for (i=1; i<s.size(); i++)
			{
				if (s[i] == 'e' && s[i-1] == 'a')
				{
					break;
				}
			}
			if (i < s.size())
			{
				++ans;
			}
			++total;
		}
		cout << (5*ans>=2*total?"dae ae ju traeligt va":"haer talar vi rikssvenska") << "\n";
	}
	return 0;
}

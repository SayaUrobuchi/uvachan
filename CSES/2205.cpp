#include <iostream>
#include <vector>
using namespace std;

int main()
{
	int n, i, j;
	vector<string> v0, v1;
	while (cin >> n)
	{
		v0 = {"0", "1"};
		for (i=2; i<=n; i++)
		{
			v1.clear();
			for (j=0; j<v0.size(); j++)
			{
				v1.emplace_back("0"+v0[j]);
			}
			for (j=v0.size()-1; j>=0; j--)
			{
				v1.emplace_back("1"+v0[j]);
			}
			swap(v0, v1);
		}
		for (i=0; i<v0.size(); i++)
		{
			cout << v0[i] << "\n";
		}
	}
	return 0;
}


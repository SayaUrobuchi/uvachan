#include <iostream>
#include <vector>
using namespace std;

int pp[128];
char s0[1024], s1[1024];
vector<int> v[128];

int main()
{
	int n, i, j, c;
	bool gg;
	while (scanf("%s%s", s0, s1) == 2)
	{
		for (i=0; i<128; i++)
		{
			v[i].clear();
			pp[i] = 0;
		}
		for (i=0; s0[i]; i++)
		{
			v[s0[i]].emplace_back(i);
		}
		n = i;
		for (i=0, j=0, gg=false; s1[i]; i++)
		{
			c = s1[i];
			if (pp[c] < v[c].size())
			{
				if (v[c][pp[c]] != j)
				{
					gg = true;
					break;
				}
				++pp[c];
				++j;
			}
		}
		puts((gg||j<n)?"FAIL":"PASS");
	}
	return 0;
}

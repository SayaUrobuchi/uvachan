#include <iostream>
#include <ctime>
#include <random>
#include <vector>
using namespace std;

int main()
{
	int n, i, j, t, choose;
	char s[32];
	vector<vector<string> > v;
	scanf("%d", &n);
	v.resize(n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		v[i].resize(t);
		for (j=0; j<t; j++)
		{
			scanf("%s", s);
			v[i][j] = s;
		}
	}
	mt19937 rndgen(time(0));
	choose = rndgen() % n;
	printf("%llu\n", v[choose].size());
	for (i=0; i<v[choose].size(); i++)
	{
		puts(v[choose][i].c_str());
	}
	return 0;
}

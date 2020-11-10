#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	int sum, t;
	string s;
	while (getline(cin, s))
	{
		stringstream ss(s);
		for (sum=0; ss>>t; sum+=t);
		printf("%d\n", sum>>1);
	}
	return 0;
}

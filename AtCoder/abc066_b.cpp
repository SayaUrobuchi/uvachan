#include <iostream>
#include <cstring>
using namespace std;

char buf[205];

int main()
{
	int i;
	scanf("%s", buf);
	string s = buf;
	int ans = 0;
	for (i=1; i+i<s.size(); i++)
	{
		if (strncmp(s.c_str(), s.c_str()+i, i) == 0)
		{
			ans = i + i;
		}
	}
	printf("%d\n", ans);
	return 0;
}

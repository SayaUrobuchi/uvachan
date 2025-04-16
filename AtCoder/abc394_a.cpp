#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	int i;
	scanf("%s", buf);
	string ans;
	for (i=0; buf[i]; i++)
	{
		if (buf[i] == '2')
		{
			ans += buf[i];
		}
	}
	puts(ans.c_str());
	return 0;
}

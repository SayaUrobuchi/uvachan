#include <iostream>
using namespace std;

const string WEATHER[] = {"Sunny", "Cloudy", "Rainy"};
const int N = 16;

char s[N];

int main()
{
	int i;
	scanf("%s", s);
	int ans;
	for (i=0; i<3; i++)
	{
		if (WEATHER[i] == s)
		{
			ans = (i + 1) % 3;
		}
	}
	puts(WEATHER[ans].c_str());
	return 0;
}

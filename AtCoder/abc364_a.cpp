#include <iostream>
using namespace std;

const int N = 128;
const int SN = 16;
const string SWEET = "sweet";

char buf[SN];

int main()
{
	int n, i;
	scanf("%d", &n);
	string last;
	int stop = n;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		string s = buf;
		if (s == SWEET && s == last)
		{
			stop = min(stop, i);
		}
		last = s;
	}
	puts(stop+1 >= n ? "Yes" : "No");
	return 0;
}

#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	int n, i;
	scanf("%d%s", &n, buf);
	string s = buf;
	int pos = -1;
	for (i=0; i+2<n; i++)
	{
		if (s.substr(i, 3) == "ABC")
		{
			pos = i + 1;
			break;
		}
	}
	printf("%d\n", pos);
	return 0;
}

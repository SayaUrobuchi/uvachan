#include <iostream>
using namespace std;

const char *KEY = "IOI";
const int N = 128;

char buf[N];

int main()
{
	int n, i, j;
	scanf("%d%s", &n, buf);
	for (i=0, j=0; i<n&&j<3; i++)
	{
		if (buf[i] == KEY[j])
		{
			++j;
		}
	}
	puts(j >= 3 ? "Yes" : "No");
	return 0;
}

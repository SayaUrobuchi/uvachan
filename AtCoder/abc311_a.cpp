#include <iostream>
using namespace std;

const int N = 128;

char s[N];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	int st = 0;
	for (i=0; s[i]&&st!=0b111; i++)
	{
		st |= (1 << (s[i] - 'A'));
	}
	printf("%d\n", i);
	return 0;
}

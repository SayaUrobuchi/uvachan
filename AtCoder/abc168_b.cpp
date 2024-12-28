#include <iostream>
using namespace std;

const int N = 128;

char buf[N];

int main()
{
	int n;
	scanf("%d%s", &n, buf);
	string s = buf;
	printf("%.*s%s\n", n, buf, s.size()>n?"...":"");
	return 0;
}

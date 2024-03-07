#include <iostream>
using namespace std;

int main()
{
	int i;
	char buf[32];
	scanf("%s", buf);
	string s = buf;
	int ans = -1;
	string str[32];
	for (i=1; i<=10; i++)
	{
		str[i] = str[i-1] + to_string(i);
		if (s == str[i])
		{
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}
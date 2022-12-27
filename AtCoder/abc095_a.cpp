#include <iostream>
using namespace std;

char buf[1024];

int main()
{
	int i, ans;
	scanf("%s", buf);
	for (i=0, ans=700; buf[i]; i++)
	{
		if (buf[i] == 'o')
		{
			ans += 100;
		}
	}
	printf("%d\n", ans);
	return 0;
}
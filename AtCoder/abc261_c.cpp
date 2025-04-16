#include <iostream>
#include <map>
using namespace std;

char buf[16];

int main()
{
	int n, i;
	map<string, int> mp;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		int c = mp[buf]++;
		printf("%s", buf);
		if (c > 0)
		{
			printf("(%d)", c);
		}
		puts("");
	}
	return 0;
}

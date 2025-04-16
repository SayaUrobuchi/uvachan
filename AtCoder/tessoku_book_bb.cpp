#include <iostream>
#include <map>
using namespace std;

const int RECORD = 1;
const int QUERY = 2;

char buf[32];

int main()
{
	int n, i;
	scanf("%d", &n);
	map<string, int> mp;
	for (i=0; i<n; i++)
	{
		int cmd;
		scanf("%d%s", &cmd, buf);
		if (cmd == RECORD)
		{
			scanf("%d", &mp[buf]);
		}
		else
		{
			printf("%d\n", mp[buf]);
		}
	}
	return 0;
}

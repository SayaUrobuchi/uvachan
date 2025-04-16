#include <iostream>
using namespace std;

const int N = 32;

char buf[N];
int cnt[128];

int main()
{
	int i;
	scanf("%s", buf);
	bool dup = false;
	for (i=0; buf[i]&&!dup; i++)
	{
		if (cnt[buf[i]])
		{
			dup = true;
		}
		cnt[buf[i]] = true;
	}
	puts(dup ? "no" : "yes");
	return 0;
}

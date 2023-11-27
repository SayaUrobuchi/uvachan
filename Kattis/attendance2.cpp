#include <iostream>
using namespace std;

const string PRESENT = "Present!";

char buf[16];

int main()
{
	int n, i;
	string last;
	scanf("%d", &n);
	bool ab = false;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		if (buf == PRESENT)
		{
			last.clear();
		}
		else
		{
			if (!last.empty())
			{
				ab = true;
				puts(last.c_str());
			}
			last = buf;
		}
	}
	if (!last.empty())
	{
		ab = true;
		puts(last.c_str());
	}
	if (!ab)
	{
		puts("No Absences");
	}
	return 0;
}

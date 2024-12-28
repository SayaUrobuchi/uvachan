#include <iostream>
using namespace std;

const string WDAY[] = {"", "Monday", "Tuesday", "Wednesday",
						"Thursday", "Friday"};

char s[16];

int main()
{
	int i;
	scanf("%s", s);
	int ans;
	for (i=1; i<=5; i++)
	{
		if (WDAY[i] == s)
		{
			ans = 6 - i;
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

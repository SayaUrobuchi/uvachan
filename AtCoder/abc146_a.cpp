#include <iostream>
using namespace std;

// SUN,MON,TUE,WED,THU,FRI,SAT
const string KEY[] = {"", "SAT", "FRI", "THU", "WED", "TUE", "MON", "SUN"};
const int N = 8;

char buf[N];

int main()
{
	int i;
	scanf("%s", buf);
	int ans;
	for (i=1; i<=7; i++)
	{
		if (KEY[i] == buf)
		{
			ans = i;
		}
	}
	printf("%d\n", ans);
	return 0;
}

#include <iostream>
using namespace std;

const int N = 8;

int main()
{
	int i;
	int last = 0;
	bool ok = true;
	for (i=0; i<N; i++)
	{
		int t;
		scanf("%d", &t);
		if (t < 100 || t > 675 || t % 25 || t < last)
		{
			ok = false;
		}
		last = t;
	}
	puts(ok ? "Yes" : "No");
	return 0;
}

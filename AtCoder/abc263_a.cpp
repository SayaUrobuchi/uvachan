#include <iostream>
using namespace std;

int t1[16], t2[8];

int main()
{
	int i;
	for (i=0; i<5; i++)
	{
		int t;
		scanf("%d", &t);
		--t2[t1[t]];
		++t1[t];
		++t2[t1[t]];
	}
	puts(t2[2] && t2[3] ? "Yes" : "No");
	return 0;
}
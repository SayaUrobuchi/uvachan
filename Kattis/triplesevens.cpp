#include <iostream>
using namespace std;

int main()
{
	int n, i, j;
	scanf("%d", &n);
	bool _777 = true;
	for (i=0; i<3; i++)
	{
		bool ok = false;
		for (j=0; j<n; j++)
		{
			int t;
			scanf("%d", &t);
			ok |= (t == 7);
		}
		_777 &= ok;
	}
	printf("%d\n", 777*_777);
	return 0;
}
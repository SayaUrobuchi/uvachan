#include <iostream>
using namespace std;

int main()
{
	int n, i, bring;
	scanf("%d", &n);
	bool escape = true;
	for (i=0, bring=0; i<n; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		bring += a;
		if (bring < b)
		{
			escape = false;
		}
	}
	printf("%spossible\n", escape?"":"im");
	return 0;
}

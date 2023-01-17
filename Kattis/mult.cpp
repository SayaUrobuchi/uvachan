#include <iostream>
using namespace std;

int main()
{
	int n, i, t, tar;
	scanf("%d", &n);
	for (i=0, tar=-1; i<n; i++)
	{
		scanf("%d", &t);
		if (tar < 0)
		{
			tar = t;
		}
		else if (t % tar == 0)
		{
			printf("%d\n", t);
			tar = -1;
		}
	}
	return 0;
}

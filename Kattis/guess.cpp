#include <iostream>
using namespace std;

char res[1024];

int main()
{
	int l, r;
	for (l=1, r=1000; l<=r; )
	{
		int mid = ((l+r) >> 1);
		printf("%d\n", mid);
		fflush(stdout);
		scanf("%s", res);
		if (*res == 'c')
		{
			break;
		}
		else if (*res == 'l')
		{
			r = mid - 1;
		}
		else
		{
			l = mid + 1;
		}
	}
	return 0;
}

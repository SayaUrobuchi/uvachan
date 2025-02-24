#include <iostream>
using namespace std;

int main()
{
	int mm, dd, y, m, d;
	scanf("%d%d", &mm, &dd);
	scanf("%d%d%d", &y, &m, &d);
	++d;
	if (d > dd)
	{
		d = 1;
		++m;
	}
	if (m > mm)
	{
		m = 1;
		++y;
	}
	printf("%d %d %d\n", y, m, d);
	return 0;
}

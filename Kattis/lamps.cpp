#include <iostream>
using namespace std;

int main()
{
	int i, hd, price;
	scanf("%d%d", &hd, &price);
	for (i=1; ; i++)
	{
		int high = 60 * (i * hd) * price;
		high += ((i * hd) + 999) / 1000 * 5 * 100000;
		int low = 11 * (i * hd) * price;
		low += 60 * 100000;
		if (low < high)
		{
			break;
		}
	}
	printf("%d\n", i);
	return 0;
}

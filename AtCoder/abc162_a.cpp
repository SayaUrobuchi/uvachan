#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	bool found = false;
	while (n && !found)
	{
		found = (n % 10 == 7);
		n /= 10;
	}
	puts(found ? "Yes" : "No");
	return 0;
}

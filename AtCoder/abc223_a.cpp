#include <iostream>
using namespace std;

int main()
{
	int money;
	scanf("%d", &money);
	bool able = (money && money % 100 == 0);
	puts(able ? "Yes" : "No");
	return 0;
}

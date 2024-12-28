#include <iostream>
using namespace std;

int main()
{
	int hp, atk;
	scanf("%d%d", &hp, &atk);
	int ans = (hp + atk - 1) / atk;
	printf("%d\n", ans);
	return 0;
}

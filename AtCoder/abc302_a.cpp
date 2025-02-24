#include <iostream>
using namespace std;

int main()
{
	long long hp, atk;
	scanf("%lld%lld", &hp, &atk);
	long long ans = (hp + atk - 1) / atk;
	printf("%lld\n", ans);
	return 0;
}

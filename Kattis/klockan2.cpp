#include <iostream>
using namespace std;

int main()
{
	int n, hour, minute, diff, ans;
	scanf("%d", &n);
	for (ans=0, diff=0; diff!=n; ans++)
	{
		diff = (diff + 55) % 3600;
	}
	printf("%02d:%02d\n", ans/60, ans%60);
	return 0;
}

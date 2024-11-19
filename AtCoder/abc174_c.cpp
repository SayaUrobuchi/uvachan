#include <iostream>
using namespace std;

const int N = 1000005;

bool used[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	int ans = -1;
	int cur = 7 % n;
	for (i=1; !used[cur]&&cur; i++, used[cur]=true, cur=(cur*10+7)%n);
	if (!cur)
	{
		ans = i;
	}
	printf("%d\n", ans);
	return 0;
}

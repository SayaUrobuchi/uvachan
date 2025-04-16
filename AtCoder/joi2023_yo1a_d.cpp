#include <iostream>
using namespace std;

const int N = 128;
const int N2 = (N << 1);

int ary[N2], cnt[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=1; i<(n<<1); i++)
	{
		scanf("%d", &ary[i]);
		++cnt[ary[i]];
	}
	int ans;
	for (i=1; i<(n<<1); i++)
	{
		if (cnt[ary[i]] == 1)
		{
			ans = ary[i];
			break;
		}
	}
	printf("%d\n", ans);
	return 0;
}

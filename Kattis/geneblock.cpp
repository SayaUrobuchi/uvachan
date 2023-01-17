#include <iostream>
using namespace std;

int tbl[15];

int main()
{
	int count, n, i, ans;
	for (i=1; i<=10; i++)
	{
		tbl[i] = tbl[i-1] + 7;
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=1, ans=-1; i<=10; i++)
		{
			if (n%10 == tbl[i]%10 && n >= tbl[i])
			{
				ans = i;
				break;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

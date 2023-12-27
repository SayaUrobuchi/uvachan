#include <iostream>
using namespace std;

const int N = 1005;

int hp[N], str[N];

int main()
{
	int n, i;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d%d", &hp[i], &str[i]);
	}
	int atk = 0;
	for (i=1; i<n; i++)
	{
		int def = i;
		while (hp[atk] > 0 && hp[def] > 0)
		{
			hp[def] -= str[atk];
			swap(def, atk);
		}
		swap(atk, def);
	}
	printf("%d\n", atk+1);
	return 0;
}

#include <stdio.h>
#include <unordered_map>

std::unordered_map<int, int> ary;

int main()
{
	int n, i, t;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		ary[t]++;
	}
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		scanf("%d", &t);
		printf("%d\n", ary[t]);
	}
	return 0;
}

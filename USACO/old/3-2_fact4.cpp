/*
	ID: sa072682
	LANG: C
	TASK: fact4
*/
#include <stdio.h>

int main()
{
	int n, i, two, ans, temp;
	freopen("fact4.in", "r", stdin);
	freopen("fact4.out", "w", stdout);
	two = 0;
	scanf("%d", &n);
	for(i=1, ans=1; i<=n; i++)
	{
		temp = i;
		if(!(temp % 2))
		{
			while(!(temp % 2))
			{
				two++;
				temp /= 2;
			}
		}
		if(!(temp % 5))
		{
			while(!(temp % 5))
			{
				two--;
				temp /= 5;
			}
		}
		ans *= temp;
		ans %= 10;
	}
	while(two--)
	{
		ans *= 2;
		ans %= 10;
	}
	printf("%d\n", ans);
	scanf(" ");
	return 0;
}

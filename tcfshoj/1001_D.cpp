#include <stdio.h>

int main()
{
	int count, n, i, t, tt;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		for(i=0, t=0; i<n; i++)
		{
			scanf("%d", &tt);
			t ^= tt;
		}
		printf(t?"No\n":"Yes\n");
	}
	return 0;
}

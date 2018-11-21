#include <stdio.h>
#include <string.h>

int min(int p, int q)
{
	if(p < q)
	{
		return p;
	}
	return q;
}

int main()
{
	int i, j, k, l1, l2, lmin, ans;
	char s1[1001], s2[1001];
	while(scanf("%s%s", s1, s2) == 2)
	{
		l1 = strlen(s1);
		l2 = strlen(s2);
		for(i=1, lmin=min(l1, l2), ans=0; i<=lmin; i++)
		{
			for(j=i-1, k=l2-1; j>-1; j--, k--)
			{
				if(s2[k] != s1[j])
				{
					break;
				}
			}
			if(j == -1)
			{
				ans = i;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}

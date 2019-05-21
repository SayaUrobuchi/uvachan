#include <stdio.h>
#include <algorithm>

const int N = 100005;

int ary[N], cnt[N], idx[N];

int main()
{
	int count, n, i, j, t, an;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		for (i=0; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		std::sort(ary, ary+n);
		for (i=0, an=0; i<n; an++)
		{
			for (j=i+1; j<n&&ary[j]==ary[i]; j++);
			idx[an] = i;
			cnt[an] = j - i;
			i = j;
		}
		if (an <= 2)
		{
			puts("Bark");
			printf("%d %d\n", ary[idx[0]], ary[idx[an-1]]);
			continue;
		}
		for (i=0, j=an-1; i<=j; )
		{
			if (cnt[i] > cnt[j])
			{
				t = cnt[j];
				cnt[i] -= t;
				cnt[i+1] += t;
				cnt[j-1] += t;
				j--;
				if (i == j || i == j-1)
				{
					puts("Bark");
					printf("%d %d\n", ary[idx[i]], ary[idx[j]]);
					break;
				}
			}
			else
			{
				t = cnt[i];
				cnt[j] -= t;
				cnt[i+1] += t;
				cnt[j-1] += t;
				i++;
				if (i == j || i == j-1)
				{
					puts("Meow");
					printf("%d %d\n", ary[idx[i]], ary[idx[j]]);
					break;
				}
			}
		}
	}
	return 0;
}

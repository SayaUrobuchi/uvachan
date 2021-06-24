#include <iostream>
#include <algorithm>

int pos[128];
char s[32768];

bool comp(char a, char b)
{
	return pos[a] < pos[b];
}

int main()
{
	int count, n, i, j, ans;
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%s", &n, s);
		for (i=0; i<n; i++)
		{
			pos[s[i]] = i;
		}
		std::sort(s, s+n, comp);
		for (i=0, ans=0; i<n; i=j)
		{
			for (j=i+1; j<n&&s[i]==s[j]; j++);
			ans += (j-i) * (pos[s[i]]-(j-1));
		}
		printf("%d\n", ans*5);
	}
	return 0;
}

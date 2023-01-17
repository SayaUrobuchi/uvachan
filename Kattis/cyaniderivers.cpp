#include <iostream>
using namespace std;

char buf[300005];

int main()
{
	int i, j, ans;
	scanf("%s", buf);
	for (i=0, ans=0; buf[i]; i=j)
	{
		if (buf[i] == '1')
		{
			j = i+1;
			continue;
		}
		for (j=i+1; buf[j]&&buf[j]==buf[i]; j++);
		ans = max(ans, (j-i+1)>>1);
	}
	printf("%d\n", ans);
	return 0;
}

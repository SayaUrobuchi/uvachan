#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int i, j;
	int ary[5];
	for (i=0; i<5; i++)
	{
		scanf("%d", &ary[i]);
	}
	sort(ary, ary+5);
	int ans = 0;
	for (i=0; i<5; i=j, ++ans)
	{
		for (j=i+1; j<5&&ary[i]==ary[j]; j++);
	}
	printf("%d\n", ans);
	return 0;
}

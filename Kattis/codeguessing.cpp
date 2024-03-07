#include <iostream>
using namespace std;

int ary[8], ans[4];
char buf[8];

int main()
{
	int i, j, k, last;
	scanf("%d%d", &ary[1], &ary[2]);
	ary[0] = 0;
	ary[3] = 10;
	scanf("%s", buf);
	sprintf(buf+4, "A");
	bool ok = true;
	bool bf = false;
	for (i=0, last=ary[0], j=0, k=0; buf[i]&&ok; i++)
	{
		if (buf[i] == 'A')
		{
			++j;
			if (bf && ans[k-1] != ary[j] - 1)
			{
				//printf(".. ans[%d] = %d, ary[%d] = %d\n", k-1, ans[k-1], j, ary[j]);
				ok = false;
			}
			last = ary[j];
			bf = false;
		}
		else
		{
			ans[k++] = last + 1;
			++last;
			bf = true;
		}
	}
	if (ok)
	{
		printf("%d %d\n", ans[0], ans[1]);
	}
	else
	{
		puts("-1");
	}
	return 0;
}

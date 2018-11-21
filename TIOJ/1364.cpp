#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int ary[1000005], m, ans;

void divv(int left, int right)
{
	int i, j, temp, loc;
	if(left >= right)
	{
		ans = ary[left];
		return;
	}
	loc = left + rand() % (right-left+1);
	temp = ary[left];
	ary[left] = ary[loc];
	ary[loc] = temp;
	for(i=left+1, j=right; ; )
	{
		for(; i<=j&&ary[i]>=ary[left]; i++);
		for(; i<=j&&ary[j]<ary[left]; j--);
		if(i > j)
		{
			break;
		}
		temp = ary[i];
		ary[i] = ary[j];
		ary[j] = temp;
		i++, j--;
	}
	temp = ary[left];
	ary[left] = ary[j];
	ary[j] = temp;
	if(j == m)
	{
		ans = ary[j];
		return;
	}
	else if(j > m)
	{
		divv(left, j-1);
	}
	else
	{
		divv(j+1, right);
	}
}

int main()
{
	int n, i;
	srand(time(NULL));
	while(scanf("%d%d", &n, &m) == 2)
	{
		for(i=0, m--; i<n; i++)
		{
			scanf("%d", &ary[i]);
		}
		divv(0, n-1);
		printf("%d\n", ans);
	}
	return 0;
}

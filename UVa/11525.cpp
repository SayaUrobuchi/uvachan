#include <stdio.h>

int f;
int ary[50005], exist[50005];

int init(int p, int q)
{
	int c, temp, temp2;
	if(p > q)
	{
		return 0;
	}
	c = ((p+q)>>1);
	temp = init(p, c-1);
	temp2 = init(c+1, q);
	ary[c] = temp;
	exist[c] = 1;
	return temp+temp2+1;
}

int del(int p, int q, int tar)
{
	int c;
	if(p > q)
	{
		return 0;
	}
	c = ((p+q)>>1);
	if(ary[c] == tar && exist[c])
	{
		printf(f?" %d":"%d", c);
		exist[c] = 0;
		f = 1;
		return 0;
	}
	else if(ary[c] > tar)
	{
		ary[c]--;
		return del(p, c-1, tar);
	}
	else
	{
		return del(c+1, q, tar-ary[c]-exist[c]);
	}
}

int main()
{
	int count, n, i, temp;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		init(1, n);
		f = 0;
		for(i=0; i<n; i++)
		{
			scanf("%d", &temp);
			del(1, n, temp);
		}
		printf("\n");
	}
	return 0;
}

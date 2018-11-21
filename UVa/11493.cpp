#include <stdio.h>
#include <string.h>

int width;
int tbl[10005];

int min(int p, int q)
{
	return p<q ? p : q;
}

int calc(int p, int q)
{
	int i, tar, now, res;
	if((p*100) % width)
	{
		return 2147483647;
	}
	tar = p*100/width;
	for(i=1, now=tbl[q]; i<=q/2; i++)
	{
		if(i+i == q)
		{
			now += (tbl[i]>>1);
		}
		else
		{
			now += min(tbl[i], tbl[q-i]);
		}
		if(now >= tar)
		{
			break;
		}
	}
	if(now < tar)
	{
		return 2147483647;
	}
	res = min(tar, tbl[q]);
	res += ((tar-res) << 1);
	return res;
}

int main()
{
	int n, m, i, t, t1, t2, num, ans;
	while(scanf("%d%d", &n, &m) == 2)
	{
		if(n == 0 && m == 0)
		{
			break;
		}
		memset(tbl, 0, sizeof(tbl));
		scanf("%d%d", &width, &num);
		for(i=0; i<num; i++)
		{
			scanf("%d", &t);
			tbl[t]++;
		}
		t1 = calc(n, m);
		t2 = calc(m, n);
		ans = 2147483647;
		if(t1 < ans)
		{
			ans = t1;
		}
		if(t2 < ans)
		{
			ans = t2;
		}
		if(ans == 2147483647)
		{
			printf("impossivel\n");
		}
		else
		{
			printf("%d\n", ans);
		}
	}
	return 0;
}

#include <stdio.h>
#include <string.h>

#define BASE 100000
#define DIGIT 2000

int temp[DIGIT], pre1[DIGIT], pre2[DIGIT], next1[DIGIT], next2[DIGIT], pl1, pl2, ql1, ql2;
int *p1, *p2, *q1, *q2, *t;

int main()
{
	int n, k, i, j;
	while(scanf("%d%d", &n, &k) == 2)
	{
		memset(pre1, 0, sizeof(pre1));
		memset(pre2, 0, sizeof(pre2));
		memset(next1, 0, sizeof(next1));
		memset(next2, 0, sizeof(next2));
		pre1[0] = 0;
		pre2[0] = k-1;
		p1 = pre1;
		p2 = pre2;
		pl1 = 1;
		pl2 = 1;
		q1 = next1;
		q2 = next2;
		for(i=2; i<=n; i++)
		{
			memset(q2, 0, sizeof(next2));
			memcpy(q1, p2, sizeof(pre1));
			ql1 = pl2;
			memset(temp, 0, sizeof(temp));
			for(j=0; j<pl2; j++)
			{
				temp[j] += p1[j] + p2[j];
				if(temp[j] >= BASE)
				{
					temp[j] -= BASE;
					temp[j+1] = 1;
				}
			}
			ql2 = pl2;
			if(temp[j])
			{
				ql2++;
			}
			for(j=0; j<ql2; j++)
			{
				q2[j] += temp[j] * (k-1);
				if(q2[j] >= BASE)
				{
					q2[j+1] = q2[j] / BASE;
					q2[j] %= BASE;
				}
			}
			if(q2[j])
			{
				ql2++;
			}
			pl1 = ql1;
			pl2 = ql2;
			t = p1;
			p1 = q1;
			q1 = t;
			t = p2;
			p2 = q2;
			q2 = t;
		}
		memset(temp, 0, sizeof(temp));
		for(j=0; j<pl2; j++)
		{
			temp[j] += p1[j] + p2[j];
			if(temp[j] >= BASE)
			{
				temp[j] -= BASE;
				temp[j+1] = 1;
			}
		}
		ql2 = pl2;
		if(temp[j])
		{
			ql2++;
		}
		printf("%d", temp[ql2-1]);
		for(i=ql2-2; i>=0; i--)
		{
			printf("%05d", temp[i]);
		}
		printf("\n");
	}
	return 0;
}

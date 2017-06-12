#include <stdio.h>
#include <string.h>

int n1[10005], n2[10005], res[10005];
char s1[10005], s2[10005];

int main()
{
	int count, i, j, nega, l1, l2, ll;
	char *p, *q;
	scanf("%d", &count);
	while(count--)
	{
		scanf("%s%s", s1, s2);
		for(p=s1; *(p+1)&&*p=='0'; p++);
		for(q=s2; *(q+1)&&*q=='0'; q++);
		l1 = strlen(p);
		l2 = strlen(q);
		ll = (l1>l2?l1:l2);
		nega = 0;
		memset(n2, 0, sizeof(n2));
		if(l1 > l2 || (l1 == l2 && strcmp(p, q) >= 0))
		{
			for(i=l1-1, j=0; i>=0; i--, j++)
			{
				n1[j] = p[i] - '0';
			}
			for(i=l2-1, j=0; i>=0; i--, j++)
			{
				n2[j] = q[i] - '0';
			}
		}
		else
		{
			nega = 1;
			for(i=l1-1, j=0; i>=0; i--, j++)
			{
				n2[j] = p[i] - '0';
			}
			for(i=l2-1, j=0; i>=0; i--, j++)
			{
				n1[j] = q[i] - '0';
			}
		}
		for(i=0; i<ll; i++)
		{
			res[i] = n1[i] - n2[i];
			if(res[i] < 0)
			{
				res[i] += 10;
				n1[i+1]--;
			}
		}
		for(i=ll-1; i>0&&res[i]==0; i--);
		if(nega)
		{
			printf("-");
		}
		for(; i>=0; i--)
		{
			printf("%d", res[i]);
		}
		printf("\n");
	}
	return 0;
}

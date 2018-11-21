#include <stdio.h>

#define BASE 100000
#define DIG 5

int f[251][250], fl[251], a[251][250], al[251];

int main()
{
	int cas, count, n, i, j, k, temp, r2, remain, shift;
	int *p, *q;
	cas = 0;
	shift = 1;
	for(i=0; i<DIG; i++)
	{
		shift *= 10;
	}
	f[1][0] = 1;
	fl[1] = 1;
	a[1][0] = 1;
	al[1] = 1;
	for(i=2; i<=250; i++)
	{
		for(j=0, temp=(i<<2)-2, p=f[i], q=f[i-1]; j<fl[i-1]; j++)
		{
			p[j] += q[j] * temp;
			if(p[j] >= BASE)
			{
				p[j+1] = p[j] / BASE;
				p[j] %= BASE;
			}
		}
		for(; p[j]; j++)
		{
			if(p[j] >= BASE)
			{
				p[j+1] = p[j] / BASE;
				p[j] %= BASE;
			}
		}
		for(k=j, j--, temp=i+1, remain=0, r2=0, q=a[i]; j>=0; j--)
		{
			remain *= shift;
			remain += p[j];
			r2 *= shift;
			r2 += p[j];
			p[j] = remain / temp;
			q[j] = (r2 >> 1);
			remain %= temp;
			r2 %= 2;
		}
		for(j=k-1; j>=0&&!p[j]; j--);
		fl[i] = ++j;
		for(j=k-1; j>=0&&!q[j]; j--);
		al[i] = ++j;
	}
	scanf("%d", &count);
	while(count--)
	{
		scanf("%d", &n);
		n >>= 1;
		p = a[n];
		printf("Case %d: %d", ++cas, p[al[n]-1]);
		for(i=al[n]-2; i>=0; i--)
		{
			printf("%0*d", DIG, p[i]);
		}
		printf("\n");
	}
	return 0;
}

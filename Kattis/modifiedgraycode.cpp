#include <iostream>
using namespace std;

const int B = 10;
const int B2 = (1 << B);

bool used[B2];
char bit[B2][B+5];

void print(int t, int idx)
{
	int i;
	bit[idx][B] = 0;
	for (i=B-1; i>=0; i--, t>>=1)
	{
		bit[idx][i] = (t & 1) + '0';
	}
}

int main()
{
	int count, n, i, j, k, last, best;
	print(0, 0);
	used[0] = true;
	for (i=1, last=0; i<B2; i++)
	{
		for (k=1; k<B2; k++)
		{
			int dif = (last ^ k);
			for (j=0; dif; j++, dif-=(dif&-dif));
			if (!(j & 1) && !used[k])
			{
				best = k;
				break;
			}
		}
		if (k >= B2)
		{
			break;
		}
		last = best;
		used[best] = true;
		print(best, i);
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d", &n);
		puts(bit[n]);
	}
	return 0;
}

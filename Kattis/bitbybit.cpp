#include <iostream>
#include <bitset>

char cmd[1024];

int main()
{
	int n, i, a, b;
	std::bitset<32> msk, val;
	while (scanf("%d", &n) == 1)
	{
		if (n == 0)
		{
			break;
		}
		msk = val = 0;
		for (i=0; i<n; i++)
		{
			scanf("%s%d", cmd, &a);
			if (*cmd == 'S')
			{
				val.set(a);
				msk.set(a);
			}
			else if (*cmd == 'C')
			{
				val.reset(a);
				msk.set(a);
			}
			else if (*cmd == 'O')
			{
				scanf("%d", &b);
				if (msk.test(a))
				{
					if (msk.test(b))
					{
						val[a] = (val[a] | val[b]);
					}
					else if (!val[a])
					{
						msk.reset(a);
					}
				}
				else if (msk.test(b) && val[b])
				{
					val.set(a);
					msk.set(a);
				}
			}
			else
			{
				scanf("%d", &b);
				if (msk.test(a))
				{
					if (msk.test(b))
					{
						val[a] = (val[a] & val[b]);
					}
					else if (val[a])
					{
						msk.reset(a);
					}
				}
				else if (msk.test(b) && !val[b])
				{
					val.reset(a);
					msk.set(a);
				}
			}
		}
		for (i=31; i>=0; i--)
		{
			if (msk.test(i))
			{
				putchar('0'+val[i]);
			}
			else
			{
				putchar('?');
			}
		}
		puts("");
	}
	return 0;
}

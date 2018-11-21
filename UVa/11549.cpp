#include <stdio.h>
#include <unordered_map>

int tbl[10];
std::unordered_map<int, int> used;

int main()
{
	int count, n, m, t, i, mx;
	long long mm;
	tbl[0] = 1;
	for (i=1; i<=9; i++)
	{
		tbl[i] = tbl[i-1] * 10;
	}
	scanf("%d", &count);
	while (count--)
	{
		scanf("%d%d", &n, &m);
		used.clear();
		mx = m;
		t = tbl[n];
		while (!used[m])
		{
			used[m] = 1;
			mm = (long long)m*m;
			while (mm >= t)
			{
				mm /= 10;
			}
			m = (int)mm;
			if (m > mx)
			{
				mx = m;
				if (mx == t)
				{
					break;
				}
			}
		}
		printf("%d\n", mx);
	}
	return 0;
}

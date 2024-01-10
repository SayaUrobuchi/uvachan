#include <iostream>
using namespace std;

const int N = 8;

bool row[N], col[N], da[N<<1], ds[N<<1];

int main()
{
	int i, j;
	bool gg = false;
	char buf[N+4];
	int cnt = 0;
	for (i=0; i<N; i++)
	{
		scanf("%s", buf);
		for (j=0; j<N; j++)
		{
			if (buf[j] == '*')
			{
				++cnt;
				gg |= (row[i] || col[j] || da[i+j] || ds[i-j+8]);
				row[i] = col[j] = da[i+j] = ds[i-j+8] = true;
			}
		}
	}
	puts(gg||cnt!=8?"invalid":"valid");
	return 0;
}

#include <iostream>
using namespace std;

const int VINIT = 7;
const int VMAX = 10;
const int VMIN = 0;

char cmd[8];

int main()
{
	int n, i, vol;
	scanf("%d", &n);
	vol = VINIT;
	for (i=0; i<n; i++)
	{
		scanf("%*s%s", cmd);
		if (*cmd == 'o')
		{
			vol = min(vol+1, VMAX);
		}
		else
		{
			vol = max(vol-1, VMIN);
		}
	}
	printf("%d\n", vol);
	return 0;
}
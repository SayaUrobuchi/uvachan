#include <iostream>
using namespace std;

int main()
{
	int i;
	int px[8], py[8];
	for (i=0; i<4; i++)
	{
		scanf("%d%d", &px[i], &py[i]);
	}
	bool conv = true;
	for (i=0; i<4; i++)
	{
		int x0 = px[(i+1)&3] - px[i];
		int y0 = py[(i+1)&3] - py[i];
		int x1 = px[(i+2)&3] - px[i];
		int y1 = py[(i+2)&3] - py[i];
		int crs = x0*y1 - x1*y0;
		if (crs < 0)
		{
			conv = false;
		}
	}
	puts(conv ? "Yes" : "No");
	return 0;
}
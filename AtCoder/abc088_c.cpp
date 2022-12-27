#include <iostream>
using namespace std;

int ary[4][4];

int main()
{
	int i, j;
	bool is_ok;
	for (i=0; i<3; i++)
	{
		for (j=0; j<3; j++)
		{
			scanf("%d", &ary[i][j]);
		}
	}
	is_ok = true;
	for (i=1; i<3&&is_ok; i++)
	{
		if (ary[i][2]-ary[i][1] != ary[0][2]-ary[0][1]
		 || ary[i][1]-ary[i][0] != ary[0][1]-ary[0][0])
		{
			is_ok = false;
		}
		if (ary[2][i]-ary[1][i] != ary[2][0]-ary[1][0]
		 || ary[1][i]-ary[0][i] != ary[1][0]-ary[0][0])
		{
			is_ok = false;
		}
	}
	if (is_ok)
	{
		puts("Yes");
	}
	else
	{
		puts("No");
	}
	return 0;
}
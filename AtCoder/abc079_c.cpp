#include <iostream>
using namespace std;

char s[5];

char tr(int i, int j)
{
	return (i & (1<<j)) ? '+' : '-';
}

int main()
{
	int i, j, t;
	scanf("%s", s);
	for (i=0; i<8; i++)
	{
		t = s[0] - '0';
		for (j=0; j<3; j++)
		{
			if (i & (1 << j))
			{
				t += s[j+1] - '0';
			}
			else
			{
				t -= s[j+1] - '0';
			}
		}
		if (t == 7)
		{
			printf("%c%c%c%c%c%c%c=7\n", s[0], tr(i, 0), s[1], tr(i, 1), s[2], tr(i, 2), s[3]);
			break;
		}
	}
	return 0;
}

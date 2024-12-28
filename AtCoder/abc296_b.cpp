#include <iostream>
using namespace std;

const int N = 16;

char buf[N];

int main()
{
	int i, j, ax, ay;
	for (i=0; i<8; i++)
	{
		scanf("%s", buf);
		for (j=0; j<8; j++)
		{
			if (buf[j] == '*')
			{
				ax = i;
				ay = j;
			}
		}
	}
	printf("%c%d\n", 'a'+ay, 8-ax);
	return 0;
}

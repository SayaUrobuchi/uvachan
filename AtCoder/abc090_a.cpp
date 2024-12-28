#include <iostream>
using namespace std;

const int N = 8;

char str[N][N];

int main()
{
	scanf("%s%s%s", str[0], str[1], str[2]);
	printf("%c%c%c\n", str[0][0], str[1][1], str[2][2]);
	return 0;
}

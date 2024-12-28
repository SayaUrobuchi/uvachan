#include <iostream>
using namespace std;

const int N = 128;

int score[128];
char s[N];

int main()
{
	int n, i;
	scanf("%d%s", &n, s);
	char winner;
	for (i=0; i<n; i++)
	{
		if (++score[s[i]] * 2 >= n)
		{
			winner = s[i];
			break;
		}
	}
	printf("%c\n", winner);
	return 0;
}

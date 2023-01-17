#include <iostream>
using namespace std;

const int len[] = {21, 5};
const char *tbl[] = {
	"qwrtypsdfghjklzxcvbnm", 
	"aeiou"
};

int main()
{
	int n, i, j, t;
	scanf("%d", &n);
	for (i=0; i<n; i++)
	{
		for (j=0, t=i; j<5; j++)
		{
			putchar(tbl[j&1][t%len[j&1]]);
			t /= len[j&1];
		}
		puts("");
	}
	return 0;
}

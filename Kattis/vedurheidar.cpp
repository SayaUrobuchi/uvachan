#include <iostream>
using namespace std;

char s[100005];

int main()
{
	int n, m, i;
	scanf("%d%d", &m, &n);
	for (i=0; i<n; i++)
	{
		int t;
		scanf("%s%d", s, &t);
		printf("%s %s\n", s, t>=m?"opin":"lokud");
	}
	return 0;
}

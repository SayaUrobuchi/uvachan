#include <iostream>
using namespace std;

int tbl[] = {4, 3, 2, 7, 6, 5, 4, 3, 2, 1};
char buf[16];

int main()
{
	int a, b, i, sum;
	scanf("%d-%d", &a, &b);
	sprintf(buf, "%06d%04d", a, b);
	for (i=0, sum=0; buf[i]; i++)
	{
		sum += (buf[i]-'0') * tbl[i];
	}
	printf("%d\n", !(sum%11));
	return 0;
}
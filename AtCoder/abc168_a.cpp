#include <iostream>
using namespace std;

const int H[] = {2,4,5,7,9};
const int P[] = {0,1,6,8};
const int B[] = {3};

string tbl[16];

int main()
{
	int i;
	for (i=0; i<5; i++)
	{
		tbl[H[i]] = "hon";
	}
	for (i=0; i<4; i++)
	{
		tbl[P[i]] = "pon";
	}
	for (i=0; i<1; i++)
	{
		tbl[B[i]] = "bon";
	}
	int n;
	scanf("%d", &n);
	puts(tbl[n%10].c_str());
	return 0;
}

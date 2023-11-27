#include <iostream>
#include <cstring>
using namespace std;

char s[128];

int main()
{
	double t;
	scanf("%s%lf", s, &t);
	printf("%.10lf\n", min(t, (double)strlen(s)));
	return 0;
}

#include <iostream>
using namespace std;

int main()
{
	int s, w;
	scanf("%d%d", &s, &w);
	puts(w>=s ? "unsafe" : "safe");
	return 0;
}

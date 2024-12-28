#include <iostream>
using namespace std;

const string KEY = "atcoder";

int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	puts(KEY.substr(a-1, b-a+1).c_str());
	return 0;
}

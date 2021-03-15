#include<iostream>
using namespace std;

int main()
{
	int n;
	while (scanf("%d", &n) == 1)
	{
		puts(n>=5550000&&n<5560000?"1":"0");
	}
	return 0;
}

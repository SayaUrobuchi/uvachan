#include <iostream>
using namespace std;

int main()
{
	int n;
	scanf("%d", &n);
	string s(n, 'o');
	printf("L%sng\n", s.c_str());
	return 0;
}

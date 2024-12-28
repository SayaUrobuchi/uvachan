#include <iostream>
using namespace std;

int main()
{
	int a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	int largest = max(a, max(b, c));
	int smallest = min(a, min(b, c));
	int mid = (a + b + c) - largest - smallest;
	printf("%d\n", mid);
	return 0;
}

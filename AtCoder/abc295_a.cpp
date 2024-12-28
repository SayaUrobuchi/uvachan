#include <iostream>
using namespace std;

const string KEY[] = { "and", "not", "that", "the", "you" };
const int N = 128;

char buf[N];

int main()
{
	int n, i, j;
	scanf("%d", &n);
	bool exist = false;
	for (i=0; i<n; i++)
	{
		scanf("%s", buf);
		for (j=0; j<5; j++)
		{
			if (KEY[j] == buf)
			{
				exist = true;
			}
		}
	}
	puts(exist ? "Yes" : "No");
	return 0;
}

#include <iostream>
using namespace std;

const int N = 4;
const int M = 4;

const int row[] = {3, 2, 1, 0};
const int col[] = {0, 2, 6, 8};
const char* ctbl = ".*";

char s[N+1];
string str[N];

void put(int a, int b, bool v)
{
	str[row[b]][col[a]] = ctbl[v];
}

int main()
{
	int i, j;
	for (i=0; i<M; i++)
	{
		str[i].resize(9, ' ');
	}
	scanf("%s", s);
	for (i=0; i<N; i++)
	{
		for (j=0; j<M; j++)
		{
			put(i, j, s[i]&(1<<j));
		}
	}
	for (i=0; i<M; i++)
	{
		puts(str[i].c_str());
	}
	return 0;
}

#include <iostream>
using namespace std;

const int N = 16;

int ary[N*N], tbl[N];

int main()
{
	int count, cas, i, j;
	cin >> count;
	for (cas=1; cas<=count; ++cas)
	{
		int n;
		cin >> n;
		for (i=0; i<n; i++)
		{
			ary[i] = i;
		}
		int head = 0;
		int tail = n;
		for (i=1; i<=n; i++)
		{
			for (j=0; j<i; j++)
			{
				ary[tail] = ary[head];
				++tail;
				++head;
			}
			tbl[ ary[head] ] = i;
			++head;
		}
		cout << tbl[0];
		for (i=1; i<n; i++)
		{
			cout << " " << tbl[i]; 
		}
		cout << "\n";
	}
	return 0;
}

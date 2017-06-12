#include <iostream>
#include <queue>

using namespace std;

bool comp(int p, int q)
{
	return p < q;
}

int main()
{
	int n, i, ary[5000];
	while(cin >> n)
	{
		if(!n) break;
		for(i=0; i<n; i++)
		{
			cin >> ary[i];
		}
		priority_queue(bool comp, ary);
	}
	return 0;
}

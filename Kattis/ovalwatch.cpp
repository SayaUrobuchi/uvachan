#include <iostream>
#include <algorithm>
using namespace std;
using pp = pair<int, int>;

const int N = 5005;
const int M = 100005;

int mat[N];
pp ary[M];

int main()
{
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i=0; i<n; i++)
	{
		mat[i] = i;
	}
	for (i=0; i<m; i++)
	{
		scanf("%d%d", &ary[i].second, &ary[i].first);
	}
	sort(ary, ary+m, greater<pp>());
	for (i=0; i<m; i++)
	{
		swap(mat[ary[i].second], mat[ary[i].second+1]);
	}
	for (i=0; i<n; i++)
	{
		printf("%d%c", mat[i], "\n "[i+1<n]);
	}
	return 0;
}

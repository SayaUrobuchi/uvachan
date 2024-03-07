#include <iostream>
using namespace std;

const int N = 100005;

string str[N];
int nxt[N], last[N];

int main()
{
	int n, i;
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (i=1; i<=n; i++)
	{
		cin >> str[i];
		nxt[i] = i;
		last[i] = i;
	}
	int ans = 1;
	for (i=1; i<n; i++)
	{
		int a, b;
		cin >> a >> b;
		nxt[last[a]] = b;
		last[a] = last[b];
		ans = a;
	}
	for (i=0; i<n; i++)
	{
		cout << str[ans];
		ans = nxt[ans];
	}
	cout << "\n";
	return 0;
}

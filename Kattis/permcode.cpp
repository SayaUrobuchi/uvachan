#include <iostream>
#include <cmath>
using namespace std;

int search(string &s, char c)
{
	int i;
	for (i=0; i<s.size()&&s[i]!=c; i++);
	return i;
}

int main()
{
	int n, i, d, p, q, id, x;
	string s, pp, c, m;
	while (cin >> x)
	{
		if (x == 0)
		{
			break;
		}
		cin >> s >> pp >> c;
		n = c.size();
		d = ((int)(pow(n, 1.5)) + x) % n;
		m.resize(n);
		p = search(s, c[d]);
		m[d] = pp[p];
		//printf(".... %d %c\n", d, m[d]);
		for (i=1; i<n; i++)
		{
			id = (d+n-i) % n;
			p = search(s, c[id]);
			q = search(s, m[(id+1)%n]);
			m[id] = pp[p^q];
		}
		cout << m << "\n";
	}
	return 0;
}

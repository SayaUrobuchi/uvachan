#include <iostream>
using namespace std;

const int C = 50;

int pos[1024];

int main()
{
	int a, b, i, cnt, ans;
	while (cin >> a >> b)
	{
		if (a == 0 && b == 0)
		{
			break;
		}
		for (i=0; i<b; i++)
		{
			pos[i] = -1;
		}
		cout << ".";
		cnt = C - 1;
		for (i=0; a>0; i++)
		{
			if (pos[a] >= 0)
			{
				ans = i - pos[a];
				break;
			}
			pos[a] = i;
			a *= 10;
			if (cnt == 0)
			{
				cout << "\n";
				cnt = C;
			}
			cout << a/b;
			cnt--;
			a %= b;
		}
		cout << "\n";
		if (a == 0)
		{
			cout << "This expansion terminates.\n\n";
		}
		else
		{
			cout << "The last " << ans << " digits repeat forever.\n\n";
		}
	}
	return 0;
}

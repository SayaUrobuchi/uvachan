#include <iostream>
#include <algorithm>
using namespace std;

const int N = 5005;

char buf[N];

int main()
{
	int n, i, j, k;
	scanf("%d", &n);
	scanf("%s", buf);
	string s = buf;
	string ans = s;
	for (i=0; i<n; i++)
	{
		if (s[i] == 'p')
		{
			int best = i;
			string t = s;
			t[i] = 'd';
			for (j=i+1; j<n; j++)
			{
				if (s[j] == 'p')
				{
					string u = s;
					reverse(u.begin()+i, u.begin()+j+1);
					for (k=i; k<=j; k++)
					{
						if (u[k] == 'd')
						{
							u[k] = 'p';
						}
						else
						{
							u[k] = 'd';
						}
					}
					if (u < t)
					{
						t = u;
					}
				}
			}
			ans = t;
			break;
		}
	}
	puts(ans.c_str());
	return 0;
}
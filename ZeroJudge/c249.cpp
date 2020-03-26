#include<iostream>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

#pragma GCC optimize ("O3")

const int N = 2049;
const int M = (N<<2)+8;

int pat[N], tbl[N][N];
int qn, qq[(N*N)>>1];
char s[N][M], *pp[N];
char buf[N<<4];

int main() {
	int count, n, n2, i, j, t, u, cur, nxt, tar;
	char *p, *q;
	ios::sync_with_stdio(0);
	cin.tie(0);
	srand( time( 0 ) );
	cin >> count;
	int ppp = 0;
	while (count-- && ++ppp<=6)
	{
		cin >> n;
		cin.getline(s[0], M);
		n2 = (n<<1);
		qn = 0;
		memset(tbl, 0, sizeof(tbl));
		for (i=1; i<=n; i++)
		{
			qq[qn++] = i;
			cin.getline(s[i], M);
			pp[i] = s[i];
		}
		for (i=n+1; i<=n2; i++)
		{
			pat[i] = 0;
			cin.getline(s[i], M);
			pp[i] = s[i];
		}
		//random_shuffle(qq, qq+qn);
		for (i=0; i<qn; i++)
		{
			cur = qq[i];
			p = pp[cur];
			for (; ; )
			{
				for (nxt=0; *p>='0'&&*p<='9'; nxt=nxt*10+*(p++)-'0');
				p++;
				nxt += n;
				if (pat[nxt] == 0)
				{
					pat[nxt] = cur;
					for (j=1, q=pp[nxt]; j<=n; j++)
					{
						for (tar=0; *q>='0'&&*q<='9'; tar=tar*10+*(q++)-'0');
						q++;
						tbl[nxt][tar] = j;
						if (tar == cur)
						{
							break;
						}
					}
					break;
				}
				else if (tbl[nxt][cur] && tbl[nxt][cur] < tbl[nxt][pat[nxt]])
				{
					qq[qn++] = pat[nxt];
					pat[nxt] = cur;
					break;
				}
			}
			pp[cur] = p;
		}
		for (i=n+1, p=buf; i<=n2; i++)
		{
			for (j=1000, t=pat[i], u=0; j>0; j/=10)
			{
				if (t >= j || u)
				{
					*(p++) = '0'+t/j;
					t %= j;
					u = 1;
				}
			}
			*(p++) = ' ';
			for (j=1000, t=i-n, u=0; j>0; j/=10)
			{
				if (t >= j || u)
				{
					*(p++) = '0'+t/j;
					t %= j;
					u = 1;
				}
			}
			*(p++) = '\n';
		}
		*p = '\0';
		cout << buf;
	}
	return 0;
}

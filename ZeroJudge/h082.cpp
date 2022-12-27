#include <iostream>
using namespace std;

const int N = 1024;

int tn, tmp[N][2];
int wn, win[N];
int ln, los[N];
int cnt[N], ord[N];
long long ap[N], bp[N];

int main()
{
	int n, t, i, j, a, b, s, m, ta, tb;
	// - 輸入戰力、應變力、初始順序，得選手序列 $C$
	scanf("%d%d", &n, &t);
	for (i=1; i<=n; i++)
	{
		scanf("%lld", &ap[i]);
	}
	for (i=1; i<=n; i++)
	{
		scanf("%lld", &bp[i]);
	}
	for (i=1; i<=n; i++)
	{
		cnt[i] = 0;
	}
	for (i=0; i<n; i++)
	{
		scanf("%d", &ord[i]);
	}
	// - 反覆至 $C$ 只剩 $1$ 名選手
	while (n > 1)
	{
		// for (i=0; i<n; i++)
		// {
			// fprintf(stderr, " %d", ord[i]);
		// }
		// fprintf(stderr, "\n");
		// for (i=1; i<=n; i++)
		// {
			// fprintf(stderr, " (%d,%d)", ap[i], bp[i]);
		// }
		// fprintf(stderr, "\n");
	    // - 進行 $1$ 個 round
	    // - 對 $C$ 兩兩配對，得到一序列 $P$，每個元素為一組數對
	    for (i=0, tn=0; i+1<n; i+=2, tn++)
	    {
	    	tmp[tn][0] = ord[i];
	    	tmp[tn][1] = ord[i+1];
	    }
		// - 對序列 $P$ 中每組數對 $(a,b)$：
		for (i=0, wn=0, ln=0; i<tn; i++)
		{
		    // - 區分勝敗並做出變化，得到勝者序列 $W$ 和敗者序列 $L$
			// - 對數對 $(a,b)$ 決定勝者 $s$ 與敗者 $m$
			a = tmp[i][0];
			b = tmp[i][1];
			if (ap[a] * bp[a] >= ap[b] * bp[b])
			{
				s = a;
				m = b;
			}
			else
			{
				s = b;
				m = a;
			}
			// - 勝者 $s$ 能力變化
			ta = (ap[s] << 1);
			tb = (bp[s] << 1);
			ap[s] += ap[m] * bp[m] / tb;
			bp[s] += ap[m] * bp[m] / ta;
			// - 敗者 $m$ 能力變化，敗場 $+1$
			ap[m] += (ap[m] >> 1);
			bp[m] += (bp[m] >> 1);
			++cnt[m];
			// - 勝者 $s$ 加入勝者序列 $W$
			win[wn] = s;
			++wn;
			// - 敗者 $m$ 加入敗者序列 $L$
			los[ln] = m;
			++ln;
		}
		// - 若存在落單者，加入勝者序列 $W$
		if (n & 1)
		{
			win[wn] = ord[n-1];
			++wn;
		}
		// - 對敗者序列 $L$ 淘汰掉敗場數 $M$ 以上的選手
		for (i=0, j=0; i<ln; i++)
		{
			if (cnt[los[i]] < t)
			{
				los[j] = los[i];
				++j;
			}
		}
		ln = j;
		// - 將 $C$ 更新為：由 $W$ 串接上 $L$
		for (i=0, tn=0; i<wn; i++, tn++)
		{
			ord[tn] = win[i];
		}
		for (i=0; i<ln; i++, tn++)
		{
			ord[tn] = los[i];
		}
		n = tn;
	}
	// - 輸出 $C$ 中剩餘選手的編號
	printf("%d\n", ord[0]);
	return 0;
}
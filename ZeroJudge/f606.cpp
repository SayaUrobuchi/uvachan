#include <iostream>
using namespace std;

const int N = 64;

int q[N][N], tbl[N][N];
int pos[N];
long long res[N];

int main()
{
	int n, m, o, i, j, k, u;
	long long f, c, ans;
	// - 處理輸入
	scanf("%d%d%d", &n, &m, &o);
	for (i=0; i<n; i++)
	{
		for (j=0; j<m; j++)
		{
			scanf("%d", &q[i][j]);
		}
	}
	// - 對 $k$ 組方案，每組一個序列 $C$：
	for (k=0; k<o; k++)
	{
		for (i=0; i<n; i++)
		{
			scanf("%d", &pos[i]);
		}
	    // - 計算方案 $C$ 的花費 $cost$
		// - 建立二維表 $T[i][j]$ 儲存城市 $i$ 需要傳輸至城市 $j$ 的流量
		for (i=0; i<m; i++)
		{
			for (j=0; j<m; j++)
			{
				tbl[i][j] = 0;
			}
		}
		// - 對 $n$ 台伺服器，每台伺服器 $s$ 做以下處理：
		for (i=0; i<n; i++)
		{
		    // - 統計由伺服器 $s$ 到各城市的流量，儲存至 $T$
			// - 找出伺服器 $s$ 所在城市 $u$
			u = pos[i];
			// - 對 $m$ 個城市，每個城市 $v$ 做以下處理：
			for (j=0; j<m; j++)
			{
			    // - 流量表 $T[u][v]$ 增加來自伺服器 $s$ 到城市 $v$ 的流量 $Q[s][v]$
			    tbl[u][j] += q[i][j];
			}
		}
		// - 對 $m$ 個城市，每個城市 $u$ 做以下處理：
		for (i=0, c=0; i<m; i++)
		{
		    // - 計算 $u$ 到其它所有城市的流量（查表 $T$），加總至 $cost$
			// - 對 $m$ 個城市，每個城市 $v$ 做以下處理：
			for (j=0; j<m; j++)
			{
			    // - 查表 $T[u][v]$ 取得流量 $f$
			    f = tbl[i][j];
			    // - 若 $u=v$ 花費 $cost$ 增加 $f\times 1$
			    if (i == j)
			    {
			    	c += f;
			    }
			    // - 否則：
			    else
			    {
			        // - 花費 $cost$ 增加 $\min(f, 1000)\times 3$
			        c += min(f, 1000LL) * 3;
			        // - 花費 $cost$ 增加 $\max(f-1000, 0)\times 2$
			        c += max(f-1000, 0LL) << 1;
			    }
			}
		}
	    // - 將花費 $cost$ 放入結果序列 $R$
	    res[k] = c;
	}
	// - 對結果序列 $R$ 找出最小值，作為答案 $ans$
	ans = res[0];
	for (i=1; i<o; i++)
	{
		ans = min(ans, res[i]);
	}
	// - 輸出最佳答案 $ans$
	printf("%lld\n", ans);
	return 0;
}
#include<iostream>
using namespace std;

int ucnt;
long long dp[128][128];
int tbl[128];

int main() {
    int n, i, j, k;
    long long m, ans, cc;
    string s;
    while (cin >> n >> m)
    {
        cin >> s;
        s = "\a" + s;
        dp[0][0] = 1;
        for (i=1; i<=n; i++)
        {
            dp[i][1] = 1;
            for (j=2; j<=i; j++)
            {
                ucnt++;
                dp[i][j] = 0;
                for (k=i-1; k>=0; k--)
                {
                    if (tbl[s[k]] != ucnt)
                    {
                        tbl[s[k]] = ucnt;
                        dp[i][j] += dp[k][j-1];
                    }
                }
                //cout << "dp[" << i << "][" << j << "] = " << dp[i][j] << '\n';
            }
        }
        ans = 0;
        for (i=n; m>0&&i>=0; i--)
        {
            ucnt++;
            for (j=n; j>=i&&m>0; j--)
            {
                if (tbl[s[j]] != ucnt)
                {
                    tbl[s[j]] = ucnt;
                    cc = dp[j][i];
                    if (cc > m)
                    {
                        cc = m;
                    }
                    ans += (long long)cc * (n-i);
                    m -= cc;
                    //cout << j << ", " << i << " " << m << '\n';
                }
            }
        }
        if (m > 0)
        {
            cout << "-1\n";
        }
        else
        {
            cout << ans << "\n";
        }
    }
    return 0;
}

#include <iostream>
using namespace std;

const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const int ord[] = {3, 1, 2};
const int START_DIR = 1;

int ans[4];

int main()
{
    int n, x, y, dir, nx, ny, tx, ty, nd, i, j;
    cin >> n >> x >> y;
    dir = START_DIR;
    for (i=1; i<n; i++, x=nx, y=ny)
    {
        cin >> nx >> ny;
        tx = nx - x;
        ty = ny - y;
        nd = 0;
        for (j=1; j<=3; j++)
        {
            if (dx[(dir+j)%4] * tx + dy[(dir+j)%4] * ty > 0)
            {
                nd = j;
            }
        }
        dir = (dir+nd) % 4;
        ++ans[nd];
    }
    cout << ans[ord[0]] << " " << ans[ord[1]] << " " << ans[ord[2]] << "\n";
    return 0;
}
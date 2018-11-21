#include <iostream>
using namespace std;

int main()
{
    int n, i, j, k, l, a, f;
    cin >> n;
    for (i=0; i<n; i++)
    {
        cin >> a >> f;
        if (i != 0)
        {
            cout << '\n';
        }
        for (j=0; j<f; j++)
        {
            if (j != 0)
            {
                cout << '\n';
            }
            for (k=1; k<=a; k++)
            {
                for (l=0; l<k; l++)
                {
                    cout << k;
                }
                cout << '\n';
            }
            for (k=a-1; k>=1; k--)
            {
                for (l=0; l<k; l++)
                {
                    cout << k;
                }
                cout << '\n';
            }
        }
    }
    return 0;
}

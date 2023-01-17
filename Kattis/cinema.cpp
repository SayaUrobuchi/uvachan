#include <iostream>
using namespace std;

int main()
{
    int n, m, i, j, t, sum;
    scanf("%d%d", &m, &n);
    for (i=0, j=0, sum=0; i<n; i++)
    {
        scanf("%d", &t);
        if (sum + t <= m)
        {
            j++;
            sum += t;
        }
    }
    printf("%d\n", n-j);
    return 0;
}

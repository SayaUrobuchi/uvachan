#include<iostream>
using namespace std;

int ary[1048576];

int main()
{
    int count, n, i, sum, cnt;
    scanf("%d", &count);
    while (count--)
    {
        scanf("%d", &n);
        for (i=0, sum=0; i<n; i++)
        {
            scanf("%d", &ary[i]);
            sum += ary[i];
        }
        for (i=0, cnt=0; i<n; i++)
        {
            if (ary[i]*n > sum)
            {
                ++cnt;
            }
        }
        printf("%.3lf%%\n", cnt*100./n);
    }
    return 0;
}


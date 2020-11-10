#include<iostream>
using namespace std;

int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        printf("%d\n", std::max(1, (n<<1)-2));
    }
    return 0;
}

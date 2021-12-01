#include <iostream>
using namespace std;

string num[] = {
    "-|| ||-", "  |  | ", "- |-| -", "- |- |-", " ||- | ",
    "-| - |-", "-| -||-", "- |  | ", "-||-||-", "-||- |-"
};

void f0(int siz, const string &s, int a)
{
    int n, i, j;
    for (i=0; i<s.size(); i++)
    {
        if (i)
        {
            cout << " ";
        }
        n = s[i] - '0';
        cout << " ";
        for (j=0; j<siz; j++)
        {
            cout << num[n][a];
        }
        cout << " ";
    }
    cout << "\n";
}

void f1(int siz, const string &s, int a, int b)
{
    int n, i, j, k;
    for (k=0; k<siz; k++)
    {
        for (i=0; i<s.size(); i++)
        {
            if (i)
            {
                cout << " ";
            }
            n = s[i] - '0';
            cout << num[n][a];
            for (j=0; j<siz; j++)
            {
                cout << " ";
            }
            cout << num[n][b];
        }
        cout << "\n";
    }
}

int main()
{
    int n;
    string s;
    while (cin >> n >> s)
    {
        if (n == 0 && s == "0")
        {
            break;
        }
        f0(n, s, 0);
        f1(n, s, 1, 2);
        f0(n, s, 3);
        f1(n, s, 4, 5);
        f0(n, s, 6);
        cout << "\n";
    }
    return 0;
}

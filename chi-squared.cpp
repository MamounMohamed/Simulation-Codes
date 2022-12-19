
#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("chiSquare.txt", "r", stdin);
    freopen("chi-Squareoutput.txt", "w", stdout);
    int n = 0, freq[10] = {};
    int x;
    while (cin >> x)
    {
        n++, freq[x]++;
    }
    long double sum = 0.0;
    for (int i = 0; i < 10; i++)
    {
        int obs = freq[i], ex = n / 10, diff = (obs - ex), diff2 = diff * diff;
        long double val = (long double)diff2 / (long double)ex;
        sum += val;
        cout << i << ' ' << obs << ' ' << ex << ' ' << diff << ' ' << diff2 << ' ' << val << '\n';
    }
    cout << n << ' ' << sum * (n / 10) << ' ' << sum << '\n';
}
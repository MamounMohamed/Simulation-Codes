#include <bits/stdc++.h>
using namespace std;
int main()
{
    freopen("Kolomogrov_in.txt", "r", stdin);
    freopen("Kolomogrov.txt", "w", stdout);
    vector<long double> x;
    long double xi;
    while (cin >> xi)
    {
        x.push_back(xi);
    }
    sort(x.begin(), x.end());
    long double maxD = 0.0;
    int n = x.size();
    for (int i = 0; i < n; i++)
    {
        long double sn = (i + 1.0) / n;
        long double sn_fn = fabs(sn - x[i]);
        cout << x[i] << ' ' << sn << ' ' << sn_fn << '\n';
        maxD = max(maxD, sn_fn);
    }
    cout << maxD << '\n';
}
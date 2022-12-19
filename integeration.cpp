#include <bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(nullptr));
    int in = 0, out = 0;
    for (int n = 0; n < 200'000'000; ++n)
    {
        long double x = (long double)2.0 + (long double)(rand()) / ((long double)(RAND_MAX / (5 - 2)));
        long double y = (long double)(rand()) / ((long double)(RAND_MAX / (125)));
        if (y <= x * x * x)
            in++;
        else
            out++;
    }
    cout << "Estimated Area : " << (long double)in / (long double)(in + out) * (3 * 125) << '\n'
    << "Real Area : " <<152.25;
}

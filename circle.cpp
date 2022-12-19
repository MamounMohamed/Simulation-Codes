#include <bits/stdc++.h>
using namespace std;
long double generate_random()
{
    return rand() * (long double)1.0 / RAND_MAX;
}
int main()
{
    srand(time(nullptr));

    int in = 0, out = 0;
    for (int i = 0; i < 200'000'000; i++)
    {
        long double x = generate_random(), y = generate_random(),
                    threshold = 1.000000000000000000000, term = x * x + y * y;

        if (term <= threshold || fabs(term - threshold) <= LDBL_EPSILON)
            in++;
        else
            out++;
    }
    cout << "estimated pi :" << ((in * 1.0) / (out + in)) * 4.0 << '\n'
         << "real pi value :" << setprecision(5) << fixed << acos(-1) << '\n';
    return 0;
}
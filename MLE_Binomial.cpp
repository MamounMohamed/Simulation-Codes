#include <bits/stdc++.h>
using namespace std;
long long n = 10, sz = 1e5;
long double p = 0.53731;
vector<long long> numbers(sz);

void generate_binomial()
{
    random_device rd;
    mt19937 gen(rd());
    binomial_distribution<> d(n, p);
    for (int i = 0; i < sz; i++)
    {
        numbers[i]=d(gen);
    }
}

long long comb(long long r)
{
    long long ans = 1, rfact = 1;
    for (long long i = n - r + 1; i < n; i++)
    {
        ans *= i;
        while (rfact <= r && ans % rfact == 0)
        {
            ans /= rfact;
            rfact++;
        }
    }
    return ans;
}

long double bin(long long n, long long x, long double p)
{
    return comb(x) * pow(p, x) * pow(1 - p, n - x);
}

long double calc_likelihood(long double prob)
{
    long double likelihood = 0.0;
    for (int i = 0; i < sz; i++)
    {
        likelihood += log10l(bin(n, numbers[i], prob));
    }
    return likelihood;
}

void get_estimation()
{
    long double l =1e-8, r = 1 - 1e-8;
    while (fabs(r - l) >= 1e-8)
    {
        long double mid1 = l + (r - l) / 3, mid2 = r - (r - l) / 3;

        if (calc_likelihood(mid1) > calc_likelihood(mid2))
            r = mid2;
        else
            l = mid1;
    }
    long double est = (calc_likelihood(r) > calc_likelihood(l) ? r : l);
    cout
        << "Estimated p : " << est << '\n'
        << "Real p : " << p << '\n'
        << "Error = " << fabs(p - est) << '\n';
}

int main()
{
    generate_binomial();
    get_estimation();
    return 0;
}
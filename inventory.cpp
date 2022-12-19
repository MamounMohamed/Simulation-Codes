#include <bits/stdc++.h>
using namespace std;
int random_dmd[25], random_lead[25], range_dmd[5], range_lead[3], m = 11, n = 5, stocks[25] = {};
double prob_dmd[5] = {0.10, 0.25, 0.35, 0.21, 0.09}, prob_lead[3] = {0.6, 0.3, 0.1};
double cum_dmd[5] = {0.10}, cum_lead[3] = {0.6};
void generate_random()
{
    for (int i = 0; i < 25; i++)
    {
        random_dmd[i] = rand() % 100;
        if ((i + 1) % n == 0)
            random_lead[i / n] = rand() % 10;
    }
}
void generate_cummulative()
{
    for (int i = 1; i < 5; i++)
    {
        cum_dmd[i] = prob_dmd[i] + cum_dmd[i - 1];
        if (i < 3)
            cum_lead[i] = prob_lead[i] + cum_lead[i - 1];
    }
}
void generate_ranges()
{
    for (int i = 0; i < 5; i++)
    {
        range_dmd[i] = (int)round(cum_dmd[i] * 100);
        if (i < 3)
            range_lead[i] = (int)round(cum_lead[i] * 10);
    }
}
int get_lead(int rn)
{
    for (int i = 0; i < 3; i++)
        if (rn < range_lead[i])
            return i + 1;
    return 0;
}

int get_demand(int rn)
{
    for (int i = 0; i < 5; i++)
        if (rn < range_dmd[i])
            return i;
    return -1;
}
void run_simulation()
{
    int stock = 3, sum_short = 0;
    stocks[2] += 8;
    for (int i = 0; i < 25; i++)
    {
        stock += stocks[i];
        int demand_rn = random_dmd[i];
        int demand = get_demand(demand_rn);
        int end_stock = max(stock - demand - sum_short, 0);
        int shortage = max(demand - stock, 0);
        sum_short = max(demand + sum_short - stock, 0);
        int lead_rn = -1, lead_time = -1;
        if ((i + 1) % n == 0)
        {
            lead_rn = random_lead[i / n];
            lead_time = get_lead(lead_rn);
            if (i + lead_time + 1 < 25)
                stocks[i + lead_time + 1] += m;
        }
        cout << demand_rn << ' ' << stock << ' ' << demand << ' ' << end_stock << ' ' << shortage << ' ' << sum_short << ' ';
        if (lead_time != -1)
            cout << lead_rn << ' ' << lead_time;
        stock = end_stock;
        cout << '\n';
    }
}
int main()
{
    srand(time(nullptr));
    generate_random();
    generate_cummulative();
    generate_ranges();
    run_simulation();
}
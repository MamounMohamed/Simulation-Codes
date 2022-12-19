#include <bits/stdc++.h>
using namespace std;
int types[3] = {35, 45, 20},
    demand[3][7] = {{3, 5, 15, 20, 35, 15, 7},
                    {10, 18, 40, 20, 8, 4, 0},
                    {44, 22, 16, 12, 6, 0, 0}},
    rn_type[10] = {86, 32, 73, 24, 76, 38, 45, 18, 44, 12},
    rn_dmd[10] = {4, 39, 66, 89, 97, 24, 9, 55, 15, 17}, max_demand = 60;
double cost = 0.33, price = 0.5;
string news_type[3] = {"good", "fair", "poor"};

void cum_news()
{
    for (int i = 1; i < 3; i++)
        types[i] += types[i - 1];
}
void cum_demand()
{
    for (int i = 0; i < 3; i++)
        for (int j = 1; j < 7; j++)
            demand[i][j] += demand[i][j - 1];
}
int get_type(int rn)
{
    for (int i = 0; i < 3; i++)
    {
        if (rn < types[i])
            return i;
    }
    return 0 ;
}
int get_demand(int typee, int rn)
{
    for (int i = 0; i < 7; i++)
        if (rn < demand[typee][i])
            return 40 + i * 10;
    return 0 ;
}
void run_simulation()
{
    for (int i = 0; i < 10; i++)
    {
        int typee = get_type(rn_type[i]);
        int demand = get_demand(typee, rn_dmd[i]);
        double sell = min(max_demand, demand) * price;
        double buy = max_demand * cost;
        double scrap = max(0.0, (max_demand - demand) * 0.05);
        double lost_prft = max(0.0, (demand - max_demand) * (price - cost));
        double final_profit = sell + scrap - lost_prft - buy;
        cout << i + 1 << ' ' << rn_type[i] << ' ' << news_type[typee] << ' ' << rn_dmd[i] << ' '
             << demand << ' ' << buy << ' ' << sell << ' ' << scrap << ' '
             << lost_prft << ' ' << final_profit << '\n';
    }
}

int main()
{
    cum_news();
    cum_demand();
    run_simulation();


}
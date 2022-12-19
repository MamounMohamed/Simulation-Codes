#include <bits/stdc++.h>
using namespace std;
char step(int num)
{
    if (num < 5)
        return 'F';
    if (num < 8)
        return 'L';
    return 'R';
}
int main()
{
    int random_numbers[] = {6, 2, 0, 6, 8, 5, 7, 7, 9, 8, 4, 8, 2, 6, 2, 1, 3, 9, 8, 4};
    int x = 1, y = 1;
    for (int i = 0; i < 20; i++)
    {
        char move = step(random_numbers[i]);
        if (move == 'F')
            y++;
        else if (move == 'L')
            x--;
        else
            x++;
        cout << i + 1 << ' ' << random_numbers[i] << ' ' << move << ' ' << x << ' ' << y << '\n';
    }
}
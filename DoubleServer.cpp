#include <bits/stdc++.h>
using namespace std;
int get_random()
{
    return rand() % 100;
}
int IAT(int rn_iat)
{
    if (rn_iat < 25)
        return 1;
    if (rn_iat < 65)
        return 2;
    if (rn_iat < 85)
        return 3;
    return 4;
}
int st(bool baker, int st_rn)
{
    if (baker)
    {
        if (st_rn < 35)
            return 3;
        if (st_rn < 60)
            return 4;
        if (st_rn < 80)
            return 5;
        return 6;
    }
    if (st_rn < 30)
        return 2;
    if (st_rn < 58)
        return 3;
    if (st_rn < 83)
        return 4;
    return 5;
}
struct job
{
    int id, rn_iat, rn_st, iat, stime = 0, arrival_time = 0, wait_time = 0, time_in_sys = 0;
};
struct server
{
    int begin = 0, idle = 0, end = 0;
    bool isbaker = 0;
    bool isAvailable(int time)
    {
        return time >= end;
    }
    int calc_idle(int time)
    {
        return (time >= end) ? time - end : 0;
    }
    string get_name()
    {
        if (isbaker)
            return "baker";
        return "able";
    }
};
void DoWork(server &p, job &j, int time)
{
    p.idle = p.calc_idle(time);
    int stime = st(p.isbaker, j.rn_st);
    p.begin = time, p.end = stime + time;
    j.stime = stime;
    j.wait_time = p.begin - j.arrival_time;
    j.time_in_sys = j.wait_time + j.stime;
    cout << j.rn_iat << ' ' << j.iat << ' ' << j.arrival_time << ' '
         << j.rn_st << ' ' << p.get_name() << ' ' << p.begin << ' ' << stime << ' '
         << p.end << ' ' << j.wait_time << ' ' << j.time_in_sys << ' '
         << p.idle << '\n';
}
server able, baker;
vector<job> jobs;

int main()
{
    freopen("Double_server.txt", "r", stdin);
    freopen("Double_ServerOutput.txt", "w", stdout);
    baker.isbaker = 1;
    for (int i = 0; i < 26; i++)
    {
        job j;
        cin >> j.id >> j.rn_iat >> j.rn_st;
        if (i > 0)
            j.arrival_time = jobs[i - 1].arrival_time + IAT(j.rn_iat);
        j.iat = IAT(j.rn_iat);
        jobs.push_back(j);
    }

    int time = 0;
    for (int i = 0; i < jobs.size(); i++)
    {
        time = max(jobs[i].arrival_time, min(able.end, baker.end));
        if (able.isAvailable(time))
        {
            DoWork(able, jobs[i], time);
        }
        else
        {
            DoWork(baker, jobs[i], time);
        }
    }
}
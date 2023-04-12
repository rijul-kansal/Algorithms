#include <bits/stdc++.h>
using namespace std;
// Tc will be O(NlogN)
struct meet
{
    int start;
    int end;
};
bool comp(meet m1, meet m2)
{
    if (m2.end > m1.end)
        return true;
    else
        return false;
}
void As(int n, int s[], int e[])
{
    meet m[n];
    for (int i = 0; i < n; i++)
    {
        m[i].start = s[i];
        m[i].end = e[i];
    }
    sort(m, m + n, comp);
    vector<int> v;
    int end = m[0].end;
    v.push_back(1);
    for (int i = 1; i < n; i++)
    {
        if (end <= m[i].start)
        {
            end = m[i].end;
            v.push_back(i + 1);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
}
// Tc will be O(NlogN)
int Minimum_Platform(int s[], int e[], int n)
{
    sort(s, s + n);
    sort(e, e + n);
    int c = 1;
    int max = 1;
    int i = 1;
    int j = 0;
    while (i < n && j < n)
    {
        if (e[j] >= s[i])
        {
            c++;
            i++;
        }
        else
        {
            c--;
            j++;
        }
        if (max < c)
        {
            max = c;
        }
    }
    return max;
}

// Tc will be O(NlogN)
struct val
{
    int pro;
    int wt;
};

bool comp1(val v1, val v2)
{
    double r1 = (double)(v1.pro) / (double)(v1.wt);
    double r2 = (double)(v2.pro) / (double)(v2.wt);
    return r1 > r2;
}

int Fractional_knapsack(int proo[], int wtt[], int n, int W)
{
    val v[n];
    for (int i = 0; i < n; i++)
    {
        v[i].pro = proo[i];
        v[i].wt = wtt[i];
    }
    sort(v, v + n, comp1);
    int curr_wt = 0;
    int profit = 0;

    for (int i = 0; i < n; i++)
    {
        if (curr_wt + v[i].wt <= W)
        {
            profit += v[i].pro;
            curr_wt += v[i].wt;
        }
        else
        {
            int x = W - curr_wt;
            double xx = double(v[i].pro) / (double)(v[i].wt);
            profit += x * xx;
            break;
        }
    }
    return profit;
}
// Tc will be O(NlogN+n*m)
struct Job
{
    int id;
    int deadline;
    int profit;
};

bool comp2(Job b1, Job b2)
{
    return b1.profit > b2.profit;
}

void Job_Scheduling(int dead[], int pro[], int n)
{
    Job jb[n];
    int x = 0;
    for (int i = 0; i < n; i++)
    {
        x = max(x, dead[i]);
        jb[i].id = i + 1;
        jb[i].deadline = dead[i];
        jb[i].profit = pro[i];
    }
    sort(jb, jb + n, comp2);
    int arr[x + 1] {0};

    int i = 0;
    int total_pro = 0;
    while (i < n)
    {
        int j = jb[i].deadline;
        while (j > 0)
        {
            if (arr[j] == 0)
            {
                arr[j] = 1;
                total_pro += jb[i].profit;
                break;
            }
            j--;
        }
        i++;
    }
    cout << total_pro;
}
int main()
{
    int s[]{2, 6, 6, 5, 4, 2, 4, 2};
    int e[]{80, 70, 65, 60, 25, 22, 20, 10};
    Job_Scheduling(s, e, 8);
    return 0;
}
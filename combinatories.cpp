#include <bits/stdc++.h>
using namespace std;
// Tc will be O(N^2)
void pascal_triangle(int n)
{
    vector<vector<int>> v(n + 1, vector<int>(n + 1, 0));

    v[0][0] = v[1][0] = v[1][1] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (j == 0 || j == i)
            {
                v[i][j] = 1;
            }
            else
            {
                v[i][j] = v[i - 1][j - 1] + v[i - 1][j];
            }
        }
    }
    int k = n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}
// Tc will be O(1)
int Birthday_paradox(double percentage)
{
    if (percentage == 0)
        return 1;
    if (percentage == 100)
        return 366;
    int count = 1;
    double num = 365;
    double dem = 365;

    double sum = 1;
    while (true)
    {
        sum *= (num / dem);
        cout << count << " " << sum << endl;
        if (sum <= percentage / 100)
        {
            break;
        }
        count++;
        num--;
    }
    return count;
}
// Exponential time
int Catalon_no(int n)
{
    if (n == 0 || n == 1)
        return 1;
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        int x = Catalon_no(i - 1);
        int y = Catalon_no(n - i);
        sum += x * y;
    }
    return sum;
}
// Tc will be O(N^2)
int Catalon_no_top_down(int n, int dp[])
{
    if (n == 0 || n == 1)
        return 1;
    if (dp[n] != 0)
    {
        return dp[n];
    }
    for (int i = 1; i <= n; i++)
    {
        int x = Catalon_no(i - 1);
        int y = Catalon_no(n - i);
        dp[n] += x * y;
    }
    return dp[n];
}
// Tc will be O(N^2)
int Catalon_no_bottom_up(int N, int dp[])
{
    dp[0] = dp[1] = 1;
    for (int n = 2; n <= N; n++)
    {
        for (int i = 1; i <= n; i++)
        {
            dp[n] += dp[i - 1] * dp[n - i];
        }
    }
    return dp[N];
}
int main()
{
    int dp[10]{0};
    cout << Catalon_no_bottom_up(3, dp);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

// Tc will be O(log2 a)
int GCD(int a, int b)
{
    if (b == 0)
        return a;
    return GCD(b, a % b);
}

vector<int> Extended_Elucid(int a, int b)
{
    if (b == 0)
    {
        return {1, 0};
    }
    vector<int> res = Extended_Elucid(b, a % b);
    int sx = res[0];
    int sy = res[1];

    int x = sy;
    int y = sx - (a / b) * sy;
    return {x, y};
}
vector<int> Extended_Elucid_GCD(int a, int b)
{
    if (b == 0)
    {
        return {1, 0, a};
    }
    vector<int> res = Extended_Elucid_GCD(b, a % b);
    int sx = res[0];
    int sy = res[1];
    int gcd = res[2];
    int x = sy;
    int y = sx - (a / b) * sy;
    return {x, y, gcd};
}
int MMI(int a, int m)
{
    vector<int> res = Extended_Elucid_GCD(a, m);

    if (res[2] != 1)
    {
        cout << "MMI not possible" << endl;
        return -1;
    }
    int ans = res[0];

    ans = (ans % m + m) % m;
    return ans;
}

vector<int> Linear_Diophantine_Eq(int a, int b, int c)
{
    int g = GCD(a, b);
    if (c % g != 0)
    {
        cout << "NOT Possible" << endl;
        return {-1};
    }
    int k = c / g;
    vector<int> arr = Extended_Elucid(a, b);

    return {k * arr[0], k * arr[1]};
}
int main()
{
    int a, b;
    cin >> a >> b;
    cout << MMI(a, b);
    return 0;
}
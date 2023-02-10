#include <bits/stdc++.h>
using namespace std;
// Tc will be O(2^mlog(m))
int Divisibility(int nn, vector<int> m)
{
    int n = m.size();
    int ans=0;

    for (int i = 1; i < (1 << n); i++)
    {
        int xx=0;
        int lcm=1;
        int j = 0;
        int x = i;
        while (x)
        {
            if (x & 1)
            {
                xx++;
                lcm*=m[j];
            }
            x = x >> 1;
            j++;
        }
        if(xx%2==0) ans-=nn/lcm;
        else ans+=nn/lcm;
    }
    cout<<ans;
}
int main()
{
    vector<int> v = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    Divisibility(10000000, v); //8471479
    return 0;
}

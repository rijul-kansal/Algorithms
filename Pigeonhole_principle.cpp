#include <bits/stdc++.h>
using namespace std;

void Subset_sum(int arr[], int n)
{
    vector<int> cum_sum;
    cum_sum.push_back(arr[0]);
    unordered_map<int, int> mp;
    for (int i = 1; i < n; i++)
    {
        cum_sum.push_back(arr[i] + cum_sum[i - 1]);
    }

    for (int i = 0; i < n; i++)
    {
        cum_sum[i] %= n;
        if (cum_sum[i] == 0)
        {
            cout << i + 1 << endl;
            for (int j = 0; j <= i; j++)
            {
                cout << arr[j] << " ";
            }
            return;
        }
        mp[cum_sum[i]]++;
    }

    int v = 0;
    for (auto x : mp)
    {
        if (x.second >= 2)
        {
            v = x.first;
            break;
        }
    }

    int xx = 0;
    int yy = 0;
    int i = 0;
    for (; i < n; i++)
    {
        if (v == cum_sum[i])
        {
            xx = i;
            break;
        }
    }
    i++;
    for (; i < n; i++)
    {
        if (v == cum_sum[i])
        {
            yy = i;
            break;
        }
    }
    cout << yy - xx << endl;
    for (int i = xx + 1; i <= yy; i++)
    {
        cout << arr[i] << " ";
    }
    return;
}
void Xor_0(int arr[], int n)
{
    unordered_map<int, int> mp;
    if (n >= 130)
    {
        cout << "Yes" << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        mp[arr[i]] = i;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            for (int k = j + 1; k < n; k++)
            {
                int temp = arr[i] ^ arr[j] ^ arr[k];
                if (mp[temp] && mp[temp] != i && mp[temp] != j && mp[temp] != k)
                {
                    cout << "YES" << endl;
                    return;
                }
            }
        }
    }
    cout << "NO" << endl;
}
int DFS(int u, int parent, vector<pair<int, int>> adj[], int n, int &ans);
void Holiday()
{
    int n;
    vector<pair<int, int>> adj[100005];
    int ans = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        adj[i].clear();
    }
    int u, v, w;
    for (int i = 1; i <=n-1; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    DFS(1, -1, adj, n, ans);
    cout << ans;
}

int DFS(int u, int parent, vector<pair<int, int>> adj[], int n, int &ans)
{
    int current_ht = 1;
    for (auto x : adj[u])
    {
        int v = x.first;
       int  wt = x.second;

        if (parent == v)
            continue;

        int Child_ht = DFS(v, u, adj, n, ans);
        ans += 2 * min(Child_ht, n - Child_ht) * wt;
        current_ht += Child_ht;
    }
    return current_ht;
}
int main()
{
    Holiday();
    return 0;
}
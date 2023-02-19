#include <bits/stdc++.h>
using namespace std;
// Tc will be O(N)
int is_Prime_1(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
// Tc will be O(N)
int is_Prime_2(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
// Tc will be O(sqrt(N))
int is_Prime_3(int n)
{
    if (n <= 1)
        return false;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
            return false;
    }
    return true;
}
// Tc will be O(NloglogN)
int N = 100000;
vector<int> Prime_seive()
{
    vector<int> Seive(N + 1, 0);
    Seive[2] = 1;
    for (int i = 3; i <= N; i += 2)
    {
        Seive[i] = 1;
    }

    for (long long int i = 3; i <= N; i++)
    {
        if (Seive[i])
            for (long long int j = i * i; j <= N; j += i)
            {
                Seive[j] = 0;
            }
    }
    return Seive;
}
// Tc will be O(NloglogN+Q+N)
void Count_prime_in_range(int Q)
{
    vector<int> Seive = Prime_seive();
    vector<int> cum_sum(N + 1, 0);
    for (int i = 1; i <= N; i++)
    {
        cum_sum[i] = cum_sum[i - 1] + Seive[i];
    }
    int a;
    int b;
    for (int i = 0; i < Q; i++)
    {
        cin >> a >> b;
        cout << cum_sum[b] - cum_sum[a - 1];
    }
}
// Tc will  be O(N)
void Prime_factors_1(int n)
{
    if (n <= 1)
    {
        cout << 1 << " ";
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        int count = 0;
        while (n && n % i == 0)
        {
            count++;
            n = n / i;
        }
        if (count >= 1)
        {
            cout << i << "^" << count << endl;
        }
    }
}
// Tc will be O(N)
void Prime_factors_2(int n)
{
    int flag = 0;
    if (n <= 1)
    {
        cout << 1 << " ";
        return;
    }
    for (int i = 2; i * i <= n; i++)
    {
        int count = 0;
        while (n && n % i == 0)
        {
            flag = 1;
            count++;
            n = n / i;
        }
        if (count >= 1)
        {
            cout << i << "^" << count << endl;
        }
    }
    if (n != 1)
    {
        cout << n << endl;
    }
}
// Tc will be O(NloglogN+QlogN)
int NN = 1000000;
void Prime_factors_queries(int Q)
{
    vector<int> Seive(NN + 1, 0);
    for (long long int i = 2; i <= NN; i++)
    {
        if (Seive[i] == 0)
        {
            Seive[i] = i;
            for (long long j = i * i; j <= NN; j += i)
            {
                if (Seive[j] == 0)
                    Seive[j] = i;
            }
        }
    }
    int n;
    for (int i = 0; i < Q; i++)
    {
        cin >> n;
        while (n >= 2)
        {
            cout << Seive[n] << " ";
            n = n / Seive[n];
        }
        cout << endl;
    }
}

void Segment_seive(int m, int n)
{
    vector<int> Seive(NN + 1, 1);
    vector<int> primes;
    vector<int> Segment(n - m + 1, 0);
    for (long long int i = 2; i <= NN; i++)
    {
        if (Seive[i])
        {
            primes.push_back(i);
            for (long long int j = i * i; j <= NN; j += i)
            {
                Seive[j] = 0;
            }
        }
    }
    for (auto p : primes)
    {
        if (p * p > n)
            break;

        int start = (m / p) * p;

        if (p >= m && p <= n)
        {
            start = 2*p;
        }

        for (int i = start; i <= n; i += p)
        {
            if (i < m)
            {
                continue;
            }
            Segment[i - m] = 1;
        }
    }

    for (int i = m; i <= n; i++)
    {
        if (Segment[i - m] == 0 && i != 1)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    return 0;
}
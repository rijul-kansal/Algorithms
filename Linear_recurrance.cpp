#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
// for fibo
// const int sz = 2;
// for fibo sum
const int sz = 3;
// Tc will be O(n)
int power_1(int a, int b)
{
    int x = a;
    for (int i = 1; i < b; i++)
    {
        x *= a;
    }
    return x;
}

// Tc will be O(log n)
int power_2(int a, int b)
{
    int res = 1;

    while (b)
    {
        if (b & 1)
        {
            res *= a;
            res % mod;
        }
        a *= a;
        a %= mod;
        b = b >> 1;
    }
    return res;
}
// TC will be O(log n)
int fast_multiplication(int a, int b, int c)
{
    int res = 0;
    while (b)
    {
        if (b & 1)
        {
            res += a;
            res %= c;
        }
        a += a;
        a %= c;
        b = b >> 1;
    }
    return res;
}

class Matrix
{
public:
    int arr[sz][sz];
    Matrix()
    {
        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                arr[i][j] = 0;
            }
        }
    }
    void Identity()
    {
        for (int i = 0; i < sz; i++)
        {
            arr[i][i] = 1;
        }
    }
    Matrix operator*(Matrix &a)
    {
        Matrix aa;

        for (int i = 0; i < sz; i++)
        {
            for (int j = 0; j < sz; j++)
            {
                for (int k = 0; k < sz; k++)
                {
                    aa.arr[i][j] += arr[i][k] * a.arr[k][j];
                    aa.arr[i][j] %= mod;
                }
            }
        }
        return aa;
    }
};
// Tc will be O(sz^3 logn )
int Fibo(int n)
{
    if (n <= 2)
        return n;
    n -= 2;

    Matrix res, t;
    res.Identity();
    t.arr[0][0] = t.arr[0][1] = t.arr[1][0] = 1;
    while (n)
    {
        if (n & 1)
        {
            res = res * t;
        }
        n = n >> 1;
        t = t * t;
    }
    return (res.arr[0][0] + res.arr[0][1]) % mod;
}
// Tc will be O(sz^3 logn )
int Fibo_sum_1(int n, int m)
{
    return (Fibo(m + 2) - Fibo(n + 1) + mod) % mod;
}
// Tc will be O(sz^3 logn )
int Fibo_sum_2(int n, int m)
{
    if (n <= -1)
        return 0;
    if (n <= 1)
        return n;
    n -= 1;

    Matrix res, t;
    res.Identity();
    t.arr[0][0] = t.arr[0][1] = t.arr[0][2] = 1;
    t.arr[1][0] = t.arr[1][1] = 1;
    t.arr[2][0] = 1;
    while (n)
    {
        if (n & 1)
        {
            res = res * t;
        }
        n = n >> 1;
        t = t * t;
    }
    return (res.arr[0][0] + res.arr[0][1]) % mod;
}
int main()
{
    return 0;
}
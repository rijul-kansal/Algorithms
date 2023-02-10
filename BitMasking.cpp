#include <bits/stdc++.h>
using namespace std;

void Odd_or_even(int n)
{
    if (n & 1)
    {
        cout << "ODD" << endl;
    }
    else
    {
        cout << "EVEN" << endl;
    }
}

int Get_ith_bit(int n, int i)
{
    int mask = 1 << i;

    return (mask & n) > 0 ? 1 : 0;
}

void Clear_ith_bit(int &n, int i)
{
    int mask = ~(1 << i);
    n = (n & mask);
}

void Set_ith_bit(int &n, int i)
{
    int mask = (1 << i);
    n = (n | mask);
}

void Update_ith_bit(int &n, int i, int v)
{
    Clear_ith_bit(n, i);
    int mask = (v << i);
    n = (n | mask);
}

void Clear_last_i_bits(int &n, int i)
{
    int mask = (-1 << i);
    n = (n & mask);
}

void Clear_range_of_bits(int &n, int i, int j)
{
    int a = -1 << (j + 1);
    int b = (1 << i) - 1;
    int mask = a | b;
    n = (n & mask);
}

void Replace(int &n, int m, int i, int j)
{
    Clear_range_of_bits(n, i, j);
    int mask = (m << i);
    n = (n | mask);
}

int power_of_2(int n)
{
    if (n & (n - 1))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

// TC will be O(log n)
int Count_set_bits_1(int n)
{
    int c = 0;
    while (n)
    {
        c += n & 1;
        n = n >> 1;
    }
    return c;
}

int Count_set_bits_2(int n)
{
    int c = 0;
    while (n)
    {
        n = n & (n - 1);
        c++;
    }
    return c;
}

int Convert_decimal_to_binary(int n)
{
    int ans = 0;
    int p = 1;
    while (n)
    {
        int last = (n & 1);
        ans += p * last;
        p *= 10;
        n = n >> 1;
    }
    return ans;
}

// TC will be O( n)
void Unique_no_1(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }
    cout << ans;
}

// TC will be O( n)
void Unique_no_2(int arr[], int n)
{
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= arr[i];
    }

    int pos = 0;
    while (ans)
    {
        if (ans & 1)
        {
            break;
        }
        pos++;
        ans = ans >> 1;
    }

    int a = 0;
    int b = 0;
    int mask = 1 << pos;

    for (int i = 0; i < n; i++)
    {
        if (mask & arr[i])
        {
            a ^= arr[i];
        }
        else
        {
            b ^= arr[i];
        }
    }
    cout << a << " " << b;
}

void fn(vector<int> &v, int no);
int convert_binary_to_decimal(vector<int> v);
void Unique_no_3(int arr[], int n)
{
    vector<int> v(64, 0);
    for (int i = 0; i < n; i++)
    {
        fn(v, arr[i]);
    }
    for (int i = 0; i < 64; i++)
    {
        v[i] %= 3;
    }

    cout << convert_binary_to_decimal(v);
}
int convert_binary_to_decimal(vector<int> v)
{
    int ans = 0;
    int p = 1;
    for (int i = 0; i < 64; i++)
    {
        ans += v[i] * p;
        p *= 2;
    }
    return ans;
}
void fn(vector<int> &v, int no)
{
    for (int i = 0; i < 64; i++)
    {
        int mask = (1 << i);
        if (mask & no)
        {
            v[i]++;
        }
    }
}

void Swap(int &a, int &b)
{
    a=a^b;
    b=b^a;
    a=a^b;
}

void Generate(string s,int n);
void Subset_Generator(string s)
{
    int n=s.length();
    for (int i = 1; i < (1<<n); i++)
    {
        Generate(s,i);
    }
    
}
void Generate(string s,int n)
{
    int j=0;
    while(n)
    {
        if(n&1)
        {
            cout<<s[j];
        }
        j++;
        n=n>>1;
    }
    cout<<endl;
}
int main()
{
   Subset_Generator("abc");
    return 0;
}

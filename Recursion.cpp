#include <bits/stdc++.h>
using namespace std;

void Sum(int n, int &s)
{
    if (n == 0)
    {
        return;
    }
    s += n;
    Sum(n - 1, s);
}
void Reversing1(int arr[], int l, int r)
{
    if (l >= r)
    {
        return;
    }
    swap(arr[l], arr[r]);
    Reversing1(arr, l + 1, r - 1);
}
void Reversing2(int arr[], int n, int i)
{
    if (i >= n / 2)
    {
        return;
    }
    swap(arr[i], arr[n - i - 1]);
    Reversing2(arr, n, i + 1);
}
bool Palindrome_check(string s, int i, int n)
{
    if (i >= n / 2)
    {
        return true;
    }
    if (s[i] != s[n - 1 - i])
        return false;
    Palindrome_check(s, i + 1, n);
}
// Tc will be O(2^N)
void Print_all_Subsequence(int arr[], vector<int> &ds, int ind, int n)
{
    if (ind == n)
    {
        for (int i = 0; i < ds.size(); i++)
        {
            cout << ds[i] << " ";
        }
        cout << endl;
        return;
    }
    ds.push_back(arr[ind]);
    Print_all_Subsequence(arr, ds, ind + 1, n);
    ds.pop_back();
    Print_all_Subsequence(arr, ds, ind + 1, n);
}
// Tc will be O(2^N)
void Print_all_Subsequence_sumK(int arr[], vector<int> &ds,
                                int ind, int n, int k, int s)
{
    if (ind == n)
    {
        if (s == k)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i] << " ";
            }
            cout << endl;
        }
        return;
    }
    s += arr[ind];
    ds.push_back(arr[ind]);
    Print_all_Subsequence_sumK(arr, ds, ind + 1, n, k, s);
    ds.pop_back();
    s -= arr[ind];
    Print_all_Subsequence_sumK(arr, ds, ind + 1, n, k, s);
}
// Tc will be O(2^N)
bool Print_Single_Subsequence_sumK(int arr[], vector<int> &ds,
                                   int ind, int n, int k, int s)
{
    if (ind == n)
    {
        if (s == k)
        {
            for (int i = 0; i < ds.size(); i++)
            {
                cout << ds[i] << " ";
            }
            cout << endl;
            return true;
        }
        return false;
    }
    s += arr[ind];
    ds.push_back(arr[ind]);
    if (Print_Single_Subsequence_sumK(arr, ds, ind + 1, n, k, s) == true)
        return true;
    ds.pop_back();
    s -= arr[ind];
    if (Print_Single_Subsequence_sumK(arr, ds, ind + 1, n, k, s) == true)
        return true;
    else
        return false;
}
// Tc will be O(2^N)
int Count_all_Subsequence_sumK(int arr[], int ind, int n, int k, int s)
{
    if (ind == n)
    {
        if (s == k)
        {
            return 1;
        }
        return 0;
    }
    s += arr[ind];
    int l = Count_all_Subsequence_sumK(arr, ind + 1, n, k, s);
    s -= arr[ind];
    int r = Count_all_Subsequence_sumK(arr, ind + 1, n, k, s);
    return l + r;
}
// Tc will be O((2^k)*k)
// first sort array
void Combination_sum1(int arr[], int n, vector<int> &ds, int ind, int target)
{
    if (ind == n)
    {
        if (target == 0)
        {
            for (auto x : ds)
            {
                cout << x << " ";
            }
            cout << endl;
        }
        return;
    }
    if (target >= arr[ind])
    {
        ds.push_back(arr[ind]);
        Combination_sum1(arr, n, ds, ind, target - arr[ind]);
        ds.pop_back();
    }
    Combination_sum1(arr, n, ds, ind + 1, target);
}
// Tc will be O((2^k)*k)
// first sort array
void Combination_sum2(int arr[], int n, vector<int> &ds, int ind, int target)
{

    if (target == 0)
    {
        for (auto x : ds)
        {
            cout << x << " ";
        }
        cout << endl;
        return;
    }
    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        if (arr[i] > target)
            break;
        ds.push_back(arr[i]);
        Combination_sum2(arr, n, ds, i + 1, target - arr[i]);
        ds.pop_back();
    }
}
// Tc will be O((2^k)*k)
// first sort array
void Subset_2(int arr[], int n, vector<int> &ds, int ind)
{
    if (ds.size() == 0)
    {
        cout << "{}" << endl;
    }
    else
    {
        for (int i = 0; i < ds.size(); i++)
        {
            cout << ds[i] << " ";
        }
        cout << endl;
    }
    for (int i = ind; i < n; i++)
    {
        if (i != ind && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        Subset_2(arr, n, ds, i + 1);
        ds.pop_back();
    }
}
// Tc will be O(n!*n)
void Permutation1(int arr[], int n, int freq[], int ind, vector<int> &ds)
{
    if (ind == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << ds[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = 0; i < n; i++)
    {
        if (freq[i] == 0)
        {
            freq[i] = 1;
            ds.push_back(arr[i]);
            Permutation1(arr, n, freq, ind + 1, ds);
            ds.pop_back();
            freq[i] = 0;
        }
    }
}
// Tc will be O(n!*n)
void Permutation2(int arr[], int n, int ind )
{
    if (ind == n)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = ind; i < n; i++)
    {
        swap(arr[i], arr[ind]);
        Permutation2(arr, n, ind + 1);
        swap(arr[i],arr[ind]);
    }
}
int main()
{
    return 0;
}
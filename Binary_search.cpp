#include <bits/stdc++.h>
using namespace std;

// STL Binary_Search
// Tc will be O(LogN)
bool BS(int arr[], int n, int key)
{
    return binary_search(arr, arr + n, key);
}
// STL Lower Bound
// Tc will be O(LogN)
int LowerBound(int arr[], int n, int key)
{
    return lower_bound(arr, arr + n, key) - arr;
}
// STL Upper_bound
// Tc will be O(LogN)
int UpperBound(int arr[], int n, int key)
{
    return upper_bound(arr, arr + n, key) - arr;
}
// Tc will be O(NLogMD)
double multiply(double n, double mid)
{
    double res = 1.0;
    for (int i = 0; i < n; i++)
    {
        res *= mid;
    }
    return res;
}

double NthRoot(double m, double n)
{
    double l = 1;
    double h = 27;
    double cap = 1e-6;
    while (h - l > 1e-6)
    {
        double mid = (l + h) / 2.0;
        double x = multiply(n, mid);
        if (x > m)
        {
            h = mid;
        }
        else
        {
            l = mid;
        }
    }
    return l;
}
// Tc will be O(Log(NlogN))
int LessThenMid(int i, vector<vector<int>> &v, int mid)
{
    int l = 0;
    int h = v[0].size() - 1;

    while (l <= h)
    {
        int md = (l + h) / 2;

        if (mid > v[i][md])
        {
            l = md + 1;
        }
        else
        {
            h = md - 1;
        }
    }
    return l;
}
int Median_Sorted_matrix(vector<vector<int>> v)
{
    int l = 1;
    int h = 1e9;
    int n = v.size();
    int m = v[0].size();
    int z = n * m / 2;
    while (l <= h)
    {
        int mid = (l + h) / 2;
        int c = 0;
        for (int i = 0; i < n; i++)
        {
            c += LessThenMid(i, v, mid);
        }

        if (c > z)
        {
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}
// Tc will be O(LogN)
int Unique_Element(int arr[], int n)
{
    int l = 0;
    int h = n - 2;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[mid] == arr[mid ^ 1])
        {
            l = mid + 1;
        }
        else
        {
            h = mid - 1;
        }
    }
    return arr[l];
}
// Tc will be O(LogN)
int Find(int arr[], int n, int target)
{
    int l = 0;
    int h = n - 1;

    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (arr[l] <= arr[mid])
        {
            if (target >= arr[l] && target <= arr[mid])
            {
                h = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        else
        {
            if (target >= arr[mid] && target <= arr[h])
            {
                l = mid + 1;
            }
            else
            {
                h = mid - 1;
            }
        }
    }
    return l;
}

double Median_sorted_array_2(vector<int> v1, vector<int> v2)
{
    if (v1.size() > v2.size())
    {
        Median_sorted_array_2(v2, v1);
    }
    int n = v1.size();
    int m = v2.size();
    int l = 0;
    int h = n;
    while (l <= h)
    {
        int c1 = (l + h) / 2;
        int c2 = (n + m + 1) / 2 - c1;
        int l1 = c1 == 0 ? INT_MIN : v1[c1 - 1];
        int l2 = c2 == 0 ? INT_MIN : v2[c2 - 1];
        int r1 = c1 == n ? INT_MAX : v1[c1];
        int r2 = c2 == m ? INT_MAX : v2[c2];

        if (l1 <= r2 && l2 <= r1)
        {
            if ((n + m) % 2 == 0)
            {
                return (max(l1, l2) + min(r1, r2)) / 2;
            }
            else
            {
                return max(l1, l2);
            }
        }
        else if (l1 > r2)
        {
            h = c1 - 1;
        }
        else
        {
            l = c1 + 1;
        }
    }
    return 0;
}
// TC will be O(NlogN)
bool isPossible(int arr[], int n, int mid, int k)
{
    int pages = 0;
    int stu = 1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > mid)
            return false;
        if ((pages + arr[i]) > mid)
        {
            stu++;
            pages = arr[i];
        }
        else
        {
            pages += arr[i];
        }
    }
    if (stu > k)
    {
        return false;
    }
    else
        return true;
}
int AllocateBooks(int arr[], int n, int k)
{
    int l = arr[0];
    int h = 0;
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        h += arr[i];
    }

    while (l <= h)
    {
        int mid = (l + h) / 2;
        if (isPossible(arr, n, mid, k))
        {
            res = mid;
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return res;
}
// TC will be O(NlogN)
bool issPossible(int arr[], int n, int k, int mid)
{
    int cows = 1;
    int cd = arr[0];
    for (int i = 1; i < n; i++)
    {
        if ((arr[i] - cd) >= mid)
        {
            cows++;
            cd = arr[i];
        }
        if (cows == k)
            return true;
    }
    return false;
}
int Agressive_Cows(int arr[], int n, int k)
{
    int l = 1;
    int h = arr[n - 1] - arr[0];
    int res = 0;
    while (l <= h)
    {
        int mid = (l + h) / 2;

        if (issPossible(arr, n, k, mid))
        {
            l = mid + 1;
            res = mid;
        }
        else
        {
            h = mid - 1;
        }
    }
    return res;
}
int main()
{
    int arr[]{5, 7, 100, 11};
    sort(arr, arr + 4);
    cout << AllocateBooks(arr, 4, 4);
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

int Is_sorted_1(int arr[], int i, int n)
{
    if (i == n - 1)
    {
        return true;
    }
    else
    {
        if (arr[i] < arr[i + 1] && Is_sorted_1(arr, i + 1, n))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int Is_sorted_2(int arr[], int n)
{
    if (n == 0 && n == 1)
    {
        return true;
    }
    else
    {
        if (arr[0] < arr[1] && Is_sorted_2(arr + 1, n - 1))
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}
int Tiling_problem(int n)
{
    if (n <= 3)
    {
        return 1;
    }
    else
    {
        return Tiling_problem(n - 1) + Tiling_problem(n - 4);
    }
}
int Binary_string(int n)
{
    if (n = 0)
    {
        return 1;
    }
    else if (n == 1)
    {
        return 2;
    }
    else
    {
        return Binary_string(n - 1) + Binary_string(n - 2);
    }
}
int Party(int n)
{
    if (n <= 1)
    {
        return 1;
    }
    else
    {
        return Party(n - 1) + Party(n - 2)*(n-1);
    }
}
int main()
{
    cout << Tiling_problem(4);
    return 0;
}
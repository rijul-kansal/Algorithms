#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int l, int h)
{
    vector<int> temp;

    int i = l;
    int mid = (l + h) / 2;
    int j = mid + 1;

    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= h)
    {
        temp.push_back(arr[j++]);
    }
    int k = 0;
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[k++];
    }
    return;
}
void Merge_sort(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        Merge_sort(arr, l, mid);
        Merge_sort(arr, mid + 1, h);
        Merge(arr, l, h);
    }
}

int partation(int arr[], int l, int h)
{
    int i = l - 1;
    int pivot = arr[h];

    for (int j = l; j <= h - 1; j++)
    {
        if (pivot >= arr[j])
        {
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[h]);
    return i + 1;
}

int Quick_select(int arr[], int k, int l, int h)
{
    int j = partation(arr, l, h);
    if (j == k)
    {
        return arr[j];
    }
    else if (j < k)
    {
        Quick_select(arr, k, j + 1, h);
    }
    else
    {
        Quick_select(arr, k, l, j - 1);
    }
}

int Merge_Count(int arr[], int l, int h)
{
    vector<int> temp;
    int c = 0;
    int i = l;
    int mid = (l + h) / 2;
    int j = mid + 1;

    while (i <= mid && j <= h)
    {
        if (arr[i] < arr[j])
        {
            temp.push_back(arr[i++]);
        }
        else
        {
            c += mid - i + 1;
            temp.push_back(arr[j++]);
        }
    }
    while (i <= mid)
    {
        temp.push_back(arr[i++]);
    }
    while (j <= h)
    {
        temp.push_back(arr[j++]);
    }
    int k = 0;
    for (int i = l; i <= h; i++)
    {
        arr[i] = temp[k++];
    }
    return c;
}
int Inversion_count(int arr[], int l, int h)
{
    if (l < h)
    {
        int mid = (l + h) / 2;
        int c1 = Inversion_count(arr, l, mid);
        int c2 = Inversion_count(arr, mid + 1, h);
        int c3 = Merge_Count(arr, l, h);
        return c1 + c2 + c3;
    }
    return 0;
}
double fn(double x)
{

    return -x * x + 3.4543767845 * x;
}
void Ternary_search()
{
    double l = -100;
    double r = 100;

    while (r - l > 1e-6)
    {
        double m1 = (2 * l + r) / 3;
        double m2 = (l + 2 * r) / 3;

        if (fn(m1) < fn(m2))
        {
            l = m1;
        }
        else
        {
            r = m2;
        }
    }
    cout << l;
}
int main()
{
    Ternary_search();

    return 0;
}
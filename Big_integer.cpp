#include <bits/stdc++.h>
using namespace std;

void Add(string a, string b)
{
    string res;
    if (a.length() > b.length())
        swap(a, b);

    reverse(a.begin(), a.end());
    reverse(b.begin(), b.end());
    int carry = 0;
    for (int i = 0; i < a.length(); i++)
    {
        int d1 = a[i] - '0';
        int d2 = b[i] - '0';
        int sum = d1 + d2 + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    for (int i = a.length(); i < b.length(); i++)
    {
        int d2 = b[i] - '0';
        int sum = d2 + carry;
        res.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry)
    {
        res.push_back('1');
    }
    reverse(res.begin(), res.end());
    cout << res;
}

void fn(vector<int> &v, int no);
void Factorial(int n)
{
    vector<int> v;
    v.push_back(1);
    for (int i = 2; i <= n; i++)
    {
        fn(v, i);
    }

    for (int i = v.size() - 1; i >= 0; i--)
    {
        cout << v[i];
    }
}
void fn(vector<int> &v, int no)
{
    int carry = 0;
    for (int i = 0; i < v.size(); i++)
    {
        int sum = v[i] * no + carry;
        v[i] = (v[i] * no + carry) % 10;
        carry = sum / 10;
    }

    while (carry)
    {
        v.push_back(carry % 10);
        carry /= 10;
    }
}

void Subtraction(string s1, string s2)
{
    if (s1.length() > s2.length())
        swap(s1, s2);
    if (s1.length() == s2.length())
    {
        int j = 0;
        while (s1[j] == s2[j] && j < s1.length())
        {
            j++;
        }
        if (s1[j] > s2[j] && j < s1.length())
            swap(s1, s2);
    }
    string res;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());

    for (int i = 0; i < s1.length(); i++)
    {
        int d1 = s1[i] - '0';
        int d2 = s2[i] - '0';
        // s2-s1
        if (d1 > d2)
        {
            d2 += 10;
            if (s2[i + 1] == '0')
            {
                int j = i + 1;
                while (s2[j] == '0')
                {
                    s2[j] = '9';
                    j++;
                }
                s2[j]--;
            }
            else
            {
                s2[i + 1]--;
            }
            res.push_back(d2 - d1 + '0');
        }
        else
        {
            res.push_back(d2 - d1 + '0');
        }
    }
    for (int i = s1.length(); i < s2.length(); i++)
    {
        res.push_back(s2[i]);
    }

    reverse(res.begin(), res.end());
    if (res.length() == 0)
        cout << 0;
    cout << res;
}
int main()
{
    string s, t;
    cin >> s >> t;
    Subtraction(s, t);
    return 0;
}
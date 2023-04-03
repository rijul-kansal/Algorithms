#include <bits/stdc++.h>
using namespace std;
// TC will be O(N!*N)
void NQueneSolve(int n, int col, vector<vector<char>> &ans, int R[], int LD[], int UD[])
{
    if (col == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    for (int row = 0; row < n; row++)
    {
        if (R[row] == 0 && LD[row + col] == 0 && UD[n - 1 + row - col] == 0)
        {
            ans[row][col] = 'Q';
            R[row] = 1;
            LD[row + col] = 1;
            UD[n - 1 + row - col] = 1;
            NQueneSolve(n, col + 1, ans, R, LD, UD);
            R[row] = 0;
            LD[row + col] = 0;
            UD[n - 1 + row - col] = 0;
            ans[row][col] = '.';
        }
    }
}
void NQueue()
{
    int n;
    cin >> n;
    vector<vector<char>> ds;
    int R[n]{0};
    int LD[2 * n - 1]{0};
    int UD[2 * n - 1]{0};
    vector<char> c;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            c.push_back('.');
        }
        ds.push_back(c);
    }
    NQueneSolve(n, 0, ds, R, LD, UD);
}

bool isPossibleSuduko(int row, int col, int no, vector<vector<int>> ans)
{
    for (int i = 0; i < 9; i++)
    {
        if (ans[row][i] == no)
            return false;
        if (ans[i][col] == no)
            return false;
        if (ans[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == no)
            return false;
    }
    return true;
}
bool Suduko_solver(vector<vector<int>> &ans)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (ans[i][j] == 0)
            {
                for (int k = 1; k <= 9; k++)
                {
                    if (isPossibleSuduko(i, j, k, ans))
                    {
                        ans[i][j] = k;
                        if (Suduko_solver(ans) == true)
                        {
                            return true;
                        }
                        else
                        {
                            ans[i][j] = 0;
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void Sudoku()
{
    int N = 9;
    vector<vector<int>> ds{
        {3, 0, 6, 5, 0, 8, 4, 0, 0},
        {5, 2, 0, 0, 0, 0, 0, 0, 0},
        {0, 8, 7, 0, 0, 0, 0, 3, 1},
        {0, 0, 3, 0, 1, 0, 0, 8, 0},
        {9, 0, 0, 8, 6, 3, 0, 0, 5},
        {0, 5, 0, 0, 9, 0, 6, 0, 0},
        {1, 3, 0, 0, 0, 0, 2, 5, 0},
        {0, 0, 0, 0, 0, 0, 0, 7, 4},
        {0, 0, 5, 2, 0, 6, 3, 0, 0}};
    Suduko_solver(ds);
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cout << ds[i][j] << " ";
        }
        cout << endl;
    }
}
// Tc will be O(N^m)
bool isPossibleColour(int m, int colours[], int graph[101][101], int n, int node)
{
    for (int i = 0; i < n; i++)
    {
        if (node != i && colours[i] == m && graph[i][node] == 1)
            return false;
    }
    return true;
}

bool MColouring(int graph[101][101], int n, int m, int colour[], int node)
{
    if (node == n)
    {
        return true;
    }

    for (int i = 1; i <= m; i++)
    {
        if (isPossibleColour(i, colour, graph, n, node))
        {
            colour[i] = i;
            MColouring(graph, n, m, colour, node + 1);
            colour[i] = 0;
        }
    }
    return false;
}
void MColourInput()
{
    int n;
    int m;
    int e;
    int graph[101][101];
    cin >> n >> m >> e;

    for (int i = 0; i < e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a - 1][b - 1] = 1;
        graph[b - 1][a - 1] = 1;
    }
    int colours[n]{0};
    cout << MColouring(graph, n, m, colours, 0);
}
bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start++] != s[end--])
            return false;
    }
    return true;
}
void Palindrome_Partationing(string s, vector<string> path, int index)
{
    if (index == s.length())
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path[i] << " ";
        }
        cout << endl;
        return;
    }

    for (int i = index; i < s.length(); i++)
    {
        if (isPalindrome(s, index, i))
        {
            path.push_back(s.substr(index, i - index + 1));
            Palindrome_Partationing(s, path, i + 1);
            path.pop_back();
        }
    }
}

void RatInMaze(vector<vector<int>> arr, vector<vector<int>> &vis,
               string s, int i, int j, int n, int ii[], int jj[])
{
    string sss = "DLRU";
    if (i == (n - 1) && j == (n - 1))
    {
        cout << s << " ";
        return;
    }
    for (int k = 0; k < n; k++)
    {
        int in = i + ii[k];
        int jn = j + jj[k];
        if (in < n && in >= 0 && jn < n && jn >= 0 && arr[in][jn] == 1 && vis[in][jn] == 0)
        {
            vis[i][j] = 1;
            RatInMaze(arr, vis, s + sss[k], in, jn, n, ii, jj);
            vis[i][j] = 0;
        }
    }
}
void RatInMazeInput()
{
    int n;
    cin >> n;
    vector<vector<int>> arr;
    vector<vector<int>> vis;
    vector<int> arr1;
    vector<int> vis1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            arr1.push_back(x);
            vis1.push_back(0);
        }
        arr.push_back(arr1);
        vis.push_back(vis1);
        arr1.clear();
    }
    string s;
    int ii[] = {1, 0, 0, -1};
    int jj[] = {0, -1, 1, 0};
    RatInMaze(arr, vis, s, 0, 0, n, ii, jj);
}
void KthPermutation(int n, int k)
{
    vector<int> prem;
    vector<int> ans;
    int fact = 1;
    for (int i = 1; i < n; i++)
    {
        prem.push_back(i);
        fact *= i;
    }
    prem.push_back(n);
    k--;
    while (true)
    {
        ans.push_back(prem[k / fact]);
        prem.erase(prem.begin() + k / fact);
        if (prem.size() == 0)
            break;
        k %= fact;
        fact /= prem.size();
    }
    for (int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
}

int main()
{
    int n, k;
    cin >> n >> k;
    KthPermutation(n, k);
    return 0;
}
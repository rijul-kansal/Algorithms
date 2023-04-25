#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
};

class open_hashing
{
    Node *arr[10];

public:
    open_hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = NULL;
        }
    }
    int Hash(int x)
    {
        return x % 10;
    }
    void Insert(int key)
    {
        int idx = Hash(key);

        Node *t = new Node;
        t->data = key;
        t->next = NULL;

        if (arr[idx] == NULL)
        {
            // cout<<1/;
            arr[idx] = t;
            return;
        }
        Node *p = arr[idx];
        Node *q = arr[idx];

        while (p && p->data < key)
        {
            q = p;
            p = p->next;
        }
        if (p == arr[idx])
        {
            arr[idx] = t;
            t->next = q;
            return;
        }
        t->next = q->next;
        q->next = t;
    }
    void Display()
    {
        for (int i = 0; i < 10; i++)
        {
            if (arr[i] != NULL)
            {
                cout << i << " ";
                Node *p = arr[i];
                while (p)
                {
                    cout << p->data << " ";
                    p = p->next;
                }
                cout << endl;
            }
        }
    }
    int Search(int key)
    {
        int idx = Hash(key);

        Node *p = arr[idx];
        while (p)
        {
            if (p->data == key)
                return 1;
            p = p->next;
        }
        return 0;
    }
};
class Closed_hashing
{
    int arr[10];

public:
    Closed_hashing()
    {
        for (int i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
    }
    int Hash(int x)
    {
        return x % 10;
    }
    int Linear_probing(int key)
    {
        for (int i = 0; i < 10; i++)
        {
            if (arr[(Hash(key) + i) % 10] == 0)
            {
                return (Hash(key)+i)%10;
            }
        }
        return -1;
    }
    int Quard_probing(int key)
    {
        for (int i = 0; i < 10; i++)
        {
            if (arr[(Hash(key) + i*i) % 10] == 0)
            {
                return (Hash(key)+i)%10;
            }
        }
        return -1;
    }
    void Insert_Linear(int key)
    {
        int idx = Linear_probing(key);
        cout<<idx;
        if (idx == -1)
        {
            return;
        }
        else
        {
            arr[idx] = key;
        }
    }
    void Insert_Quard(int key)
    {
        int idx = Quard_probing(key);
        cout<<idx;
        if (idx == -1)
        {
            return;
        }
        else
        {
            arr[idx] = key;
        }
    }
    void Display()
    {
        for (int i = 0; i < 10; i++)
        {
            cout<<i<<" "<<arr[i]<<endl;
        }
        
    }
};
int main()
{
    return 0;
}
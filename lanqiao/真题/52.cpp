#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool debug = false;

int a, b, n;
vector<int> res;

void div(int &a, int b, int &result, int &remain)
{
    result = 0;
    while (a >= b)
    {
        a -= b;
        result++;
    }
    remain = a;
}

void push(int n)
{
    if (n >= 10)
    {
        n -= 10;
        int count = 0;
        for (int i = res.size() - 1; i >= 0; i--)
        {
            res[i] ++;
            if (count++ > 6) break;
            if (res[i] >= 10)
            {
                res[i] -= 10;
            }
            else
            {
                break;
            }
        }
    }

    res.push_back(n);
    int len = res.size();
    if(len > 20) {
        for(int i = 0; i < 3; i++) {
            res[i] = res[len - 3 + i];  
        }
        res.resize(3);
        if(debug) {
            cout << "after resize:" << endl;
            for(int i = 0; i < res.size();i++) {
                cout << res[i] << " ";
            }
            cout << endl;
        }
    }
    if (debug)
    {
        cout << "pushed: " << n << endl;
    }
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
        debug = true;
    if (debug)
    {
        freopen("52", "r", stdin);
    }
    cin >> a >> b >> n;
    while (a >= b)
    {
        a -= b;
    }
    if (debug)
    {
        cout << a << endl;
    }

    int cur = 0;

    while (cur != n + 3)
    {
        if (a < b)
        {
            if (debug)
                cout << a << " < " << b << " ";
            a *= 10;
            cur++;
            push(0);
        }
        else
        {
            if (debug)
                cout << a <<" >= " << b << " ";
            int result, remain;
            div(a, b, result, remain);
            cur++;
            
            push(result);
            a *= 10;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << res[res.size() + i - 3];
    }

    cout << endl;

    return 0;
}

#include <iostream>
#include <vector>
#include <list>
using namespace std;

unsigned long long n, m;
// int mutex[40];

int opp[7] = {0, 4, 5, 6, 1, 2, 3};

vector<list<int> > mutex(7);
/*
level:
num: 上一层的数字

*/
int add(int level, int num)         
{
    if(level == n + 1) return 1;
    unsigned long long res = 0;
    
    for(list<int>::iterator it = mutex[num].begin(); it != mutex[num].end(); it++)
    {
        res += 4 * add(level + 1, opp[*it]);
        if(res >= 1000000007) res -= 1000000007;
    }



    return res;
}

int main(int argc, char const *argv[])
{
    cin >> n >> m;

    for (int i = 0; i < 7; i++)
    {
        for (int j = 1; j <= 6; j++)
            mutex[i].push_back(j);
    }

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        mutex[a].remove(b);
        mutex[b].remove(a);
    }

    for(int i = 0; i < 7;i++)
    {
        for(list<int>::iterator it = mutex[i].begin(); it != mutex[i].end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }

    cout << add(1, 0) << endl;



    return 0;
}

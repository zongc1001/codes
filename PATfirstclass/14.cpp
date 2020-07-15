#include <cstdio>
#include <stack>
#include <list>
#include <algorithm>
#include <vector>
#include <deque>
#include <queue>
using namespace std;
const bool debug = false;
struct Costumer
{
    int num;          // 1 ~ k
    int doneTime = 0; // 8*60 ~
    int transcation = 0;
};
bool cmp(Costumer &a, Costumer &b)
{
    return a.num < b.num;
}

int n, m, k, q;
int query[1000 + 5];
typedef queue<Costumer> window;
vector<window> bank;
vector<Costumer> res;

int findWindow()
{
    int min = 9999999, res;
    for (int i = 1; i <= n; i++)
    {
        if (bank[i].front().doneTime < min)
        {
            res = i;
            min = bank[i].front().doneTime;
        }
    }
    return res;
}

void complete()
{
    for (int i = n * m + 1; i <= k; i++)
    {
        Costumer a;
        a.num = i;
        scanf("%d", &a.transcation);
        int t = findWindow();
        a.doneTime = bank[t].back().doneTime + a.transcation;
        bank[t].push(a);
        bank[t].pop();
        res.push_back(a);
    }
}

int main(int argc, char const *argv[])
{
    if (debug)
        freopen("14.txt", "r", stdin);
    scanf("%d %d %d %d", &n, &m, &k, &q);
    bank.resize(n + 1);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n && n * (i - 1) + j <= k; j++)
        {
            Costumer a;
            a.num = n * (i - 1) + j;
            scanf("%d", &a.transcation);
            a.doneTime = a.transcation + (bank[j].empty() ? 8 * 60 : bank[j].back().doneTime);
            bank[j].push(a);
            res.push_back(a);
        }
    }

    if (debug)
    {
        printf("\n----res[i].num-----\n");
        for (int i = 0; i < res.size(); i++)
        {
            printf("%d ", res[i].num);
        }
        printf("\n-----------\n\n");
    }

    complete();
    sort(res.begin(), res.end(), cmp);

    for (int i = 0; i < q; i++)
    {
        int t;
        scanf("%d", &t);
        int temp = res[t - 1].doneTime;
        if (temp - res[t - 1].transcation >= 17 * 60)
            printf("Sorry\n");
        else
            printf("%02d:%02d\n", temp / 60, temp % 60);
    }

    return 0;
}

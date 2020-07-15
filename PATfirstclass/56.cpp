//https://pintia.cn/problem-sets/994805342720868352/problems/994805419468242944
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
bool debug = false;

typedef pair<int, int> bind;
struct Obj
{
    int weight, order, rank;
};
int p, g;
vector<bind> weight;
vector<int> permutaion;
vector<Obj> nodes;

// void findMost(int begin, int end)
// {
//     int max = -1, index = 0;
//     for(int i = begin; i < end; i++)
//     {
//         if(nodes[i])
//     }
// }
int getRank(vector<Obj> &nodes, queue<bind> &q)
{

    if (debug)
    {
        printf("entry getrank()-----------------------\n");
        int size = q.size();
        while (size--)
        {
            printf("(%d, %d) ", q.front());
            q.push(q.front());
            q.pop();
        }
        printf("\n------------------------------\n");
    }

    if (q.size() == 1)
    {
        weight[q.front().first].second = 1;
        if (debug)
            printf("!!!q.front().first: %d\n", q.front().first);
        q.pop();
        return 1;
    }
    int size = q.size();

    int rankedNum = q.size();
    vector<bool> willBeRank;
    willBeRank.resize(nodes.size(), true);
    for (int i = 0; i < size; i += g)
    {
        int max = -1;
        bind temp;
        int j;
        for (j = i; j < i + g && j < size; j++)
        {
            if (debug)
                printf("(%d, %d) ", q.front().first, q.front().second);
            if (q.front().second > max)
            {
                max = q.front().second;
                temp = q.front();
            }
            q.pop();
        }
        q.push(temp);

        willBeRank[temp.first] = false;
        rankedNum--;
    }
    if (debug)
        printf("\n");
    int getrank = 1 + getRank(nodes, q);
    if (debug)
    {
        printf("getRank: %d\n", getrank);
    }
    for (int i = 0; i < willBeRank.size(); i++)
    {
        if (willBeRank[i])
        {
            if (debug)
                printf("(wbr:%d) ", i);
            weight[i].second = getrank;
        }
    }
    if (debug)
        printf("\n");
    return rankedNum + getrank - 1;
}

int main(int argc, char const *argv[])
{
    if (debug)
        freopen("56.txt", "r", stdin);
    scanf("%d %d", &p, &g);

    int tempInput;
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &tempInput);
        weight.push_back(bind(tempInput, 0));
    }
    for (int i = 0; i < p; i++)
    {
        scanf("%d", &tempInput);
        permutaion.push_back(tempInput);
    }
    nodes.resize(p);
    queue<bind> q;

    for (int i = 0; i < p; i++)
    {
        Obj &a = nodes[i];
        a.order = permutaion[i];
        a.weight = weight[a.order].first;
        q.push(bind(a.order, a.weight));
    }
    if (debug)
    {
        for (int i = 0; i < p; i++)
        {
            printf("(%d, %d) ", nodes[i].order, nodes[i].weight);
        }
        printf("\n");
    }

    //开始排阶
    getRank(nodes, q);
    for (int i = 0; i < weight.size(); i++)
    {
        if (i != 0)
            printf(" ");
        printf("%d", weight[i].second);
    }

    return 0;
}

#include <cstdio>
#include <vector>
using namespace std;
bool debug = false;
int n, m;
int arr[105][105];
vector<vector<int> > room;


bool arrangeToOldRoom(int n)
{
    for (int i = 0; i < room.size(); i++)
    {
        bool flag = true;
        for (int j = 0; j < room[i].size(); j++)
        {
            if (arr[room[i][j]][n])
            {
                return false;
            }
        }
        if (flag)
        {
            room[i].push_back(n);
            return true;
        }
    }
    return false;
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
        debug = true;
    if (debug)
        freopen("53", "r", stdin);
    scanf("%d %d", &n, &m);
    while (m--)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    vector<bool> arranged(1 + n);
    for (int i = 1; i <= n; i++)
    {
        arranged[i] = false;
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if (arranged[i])
            continue;
        if (arrangeToOldRoom(i)) {
            continue;
            if(debug) {
                printf("arrangeTooldroom: %d\n", i);
            }
        }
        res++;
        vector<int> vec;
        vec.push_back(i);
        for (int j = 1; j <= n; j++)
        {
            if (arranged[j])
                continue;
            bool flag = true;
            for (int t = 0; t < vec.size(); t++)
            {
                if (arr[vec[t]][j])
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
            {
                vec.push_back(j);
                arranged[j] = true;
            }
        }
        room.push_back(vec);
    }

    printf("%d\n", res);

    return 0;
}

//https://pintia.cn/problem-sets/994805342720868352/problems/994805500414115840
#include <cstdio>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m, k;
typedef vector<int> roads;




int main(int argc, char const *argv[])
{
    scanf("%d %d %d", &n, &m, &k);
    // printf("%d %d %d", n, m, k);
    vector<roads> vec(n + 1);
    vector<bool> visited(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        vec[a].push_back(b);
        vec[b].push_back(a);
    }
    for (int i = 0; i < k; i++)
    {
        int tempk;
        scanf("%d", &tempk);
        visited.assign(n + 1, false);
        
        int subgraph = 0;
        for(int j = 1; j <= n;j++)
        {
            if(tempk != j && vec[j].size() == n-1)
            {
                subgraph = 1;
                break;
            }
            if(tempk != j && !visited[j])
            {
                subgraph++;
                queue<int> q;
                q.push(j);
                while(!q.empty())
                {
                    int temp = q.front();
                    q.pop();
                    visited[temp] = true;
                    for(int t = 0; t < vec[temp].size();t++)
                    {
                        if(vec[temp][t] != tempk && !visited[vec[temp][t]])
                        {
                            q.push(vec[temp][t]);
                        }
                    }


                }
            }
        }
        printf("%d\n", subgraph - 1);
    }


    return 0;
}

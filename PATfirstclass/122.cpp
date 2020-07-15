// https://pintia.cn/problem-sets/994805342720868352/problems/994805351814119424

#include <cstdio>
#include <vector>
using namespace std;
bool debug = false;
int n, m, q;
int edge[205][205];
vector<bool> vis;
vector<int> list;
int main(int argc, char const *argv[]) {
    if (debug) freopen("122", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        // if(a >= 1 && a <= n && b >= 1; b <= n)
        edge[a][b] = 1;
        edge[b][a] = 1;
    }
    scanf("%d", &q);
    list.resize(n + 1);
    while (q--) {
        int k;
        scanf("%d", &k);
        if (k != n + 1) {
            for (int i = 0; i < k; i++) {
                int temp;
                scanf("%d", &temp);
            }
            printf("NO\n");
        } else {
            vis.assign(n + 1, false);
            list.clear();
            for (int i = 0; i < k; i++) {
                int temp;
                scanf("%d", &temp);
                list.push_back(temp);
            }
            // printf("size: %d\n", list.size());
            if (debug) {
                printf("%d %d\n", list.front(), list.back());
            }
            if (list.front() != list.back()) {
                printf("NO\n");
            } else {
                int last = list[0], next = list[1];
                int cnt = 0;
                int index = 2;
                vis.assign(n + 1, false);
                while (true) {
                    if (debug) {
                        printf("(last, end): (%d, %d)\n", last, next);
                    }
                    if (edge[last][next] == 1 && !vis[next]) {
                        vis[next] = true;
                        cnt++;
                        last = next;
                        next = list[index++];
                        if(cnt == n) break;
                    } else {
                        break;
                    }
                }
                if (debug) printf("cnt: %d\n", cnt);
                if (cnt == n) printf("YES\n"); 
                else printf("NO\n");
            }
        }
    }

    return 0;
}

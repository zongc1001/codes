#include <cstdio>
#include <stack>
#include <vector>
using namespace std;
bool debug = false;
int n, m;
int arr[105][105];
vector<vector<int> > room;
int res = 999;

//确认cur是否可以插入已存在的考场
bool check(int roomNum, int cur) {
    for (int i = 0; i < room[roomNum].size(); i++) {
        if (arr[cur][room[roomNum][i]]) {
            return false;
        }
    }
    return true;
}

void dfs(int cur, int num) {
    if (debug) {
        printf("enter dfs, cur: %d, num: %d\n", cur, num);
    }
    if (num >= res) return;
    else if(cur == n + 1) {
        //一趟遍历的终点
        res = num < res ? num : res;
        return;
    }
    
    for (int i = 0; i < room.size(); i++) {
        //如果能够插入到之前的考场，应该把各种情况都试一遍
        if (check(i, cur)) {
            room[i].push_back(cur);
            dfs(cur + 1, num);
            room[i].pop_back();
        }
    }
    //试过了插入到之前考场，还应该尝试新建考场
    room.push_back(vector<int>());
    room[room.size() - 1].push_back(cur);
    dfs(cur + 1, num + 1);
    room.pop_back();
}

int main(int argc, char const *argv[]) {
    if (argc > 1) debug = true;
    if (debug) freopen("53", "r", stdin);
    scanf("%d %d", &n, &m);
    while (m--) {
        int a, b;
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    if (debug) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                printf("%d ", arr[i][j]);
            }
            printf("\n");
        }
    }

    // vector<bool> arranged(1 + n);
    // for (int i = 1; i <= n; i++) {
    //     arranged[i] = false;
    // }

    dfs(1, 0);
    printf("%d\n", res);
    return 0;
}

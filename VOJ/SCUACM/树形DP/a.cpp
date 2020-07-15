#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
typedef unsigned long long ull;

struct Road {
    int des;
    ull len;
    Road(int des, ull len) : des(des), len(len) {}
};

bool debug = false;
vector<vector<Road> > roads;
int n;
vector<bool> visited;
vector<ull> maxDis;

int bfs(int cur) {
    queue<Road> q;
    q.push(Road(cur, 0));
    int res = 1;
    ull maxlen = 0;
    while (!q.empty()) {
        int loops = q.size();
        while (loops--) {
            Road cur(q.front());
            if (debug) {
                cout << "(" << cur.des << ", " << cur.len << ")"
                     << " ";
            }
            q.pop();
            visited[cur.des] = true;
            ull curDis = cur.len;
            if (curDis > maxlen) {
                maxlen = curDis;
                res = cur.des;
            }
            if (curDis > maxDis[cur.des]) {
                maxDis[cur.des] = curDis;
            }
            for (int i = 0; i < roads[cur.des].size(); i++) {
                if (!visited[roads[cur.des][i].des]) {
                    q.push(Road(roads[cur.des][i].des,
                                curDis + roads[cur.des][i].len));
                }
            }
        }
    }
    return res;
}

int findMax() {
    ull max = 0;
    int index;
    for (int i = 1; i <= maxDis.size(); i++) {
        if (maxDis[i] > max) {
            max = maxDis[i];
            index = i;
        }
    }
    return index;
}

int main(int argc, char const *argv[]) {
    if (argc > 1) debug = true;
    if (debug) freopen("a", "r", stdin);
    cin >> n;
    roads.resize(n + 1);
    maxDis.resize(n + 1, 0);
    for (int i = 2; i <= n; i++) {
        ull a, b;
        cin >> a >> b;
        roads[i].push_back(Road(a, b));
        roads[a].push_back(Road(i, b));
    }

    if (debug) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < roads[i].size(); j++) {
                cout << "(" << roads[i][j].des << ", " << roads[i][j].len << ")"
                     << " ";
            }
            cout << endl;
        }
    }

    int temp = 1;
    for (int i = 0; i < 3; i++) {
        visited.assign(n + 1, false);
        if (debug)
            cout << "\n\t"
                 << "bfs from " << temp << endl;
        temp = bfs(temp);
        if(debug) cout << endl;
    }

    for (int i = 1; i <= n; i++) {
        cout << maxDis[i] << endl;
    }

    return 0;
}

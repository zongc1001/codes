#include <cmath>
#include <cstdio>
#include <map>
#include <string>
#include <vector>
using namespace std;
const bool debug = false;
int n, k;
map<int, int> m;
bool isPrime(int n) {
    if (n <= 1)
        return true;
    else {
        for (int i = 2; i <= sqrt(n); i++) {
            if (n % i == 0) {
                return false;
            }
        }
        return true;
    }
}

int main(int argc, char const *argv[]) {
    if (debug) freopen("116", "r", stdin);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        int a;
        scanf("%d", &a);
        if (m.find(a) == m.end()) {
            m[a] = i;
        }
    }

    vector<bool> visited;
    visited.resize(n + 2, false);
    scanf("%d", &k);
    for (int i = 1; i <= k; i++) {
        int a;
        scanf("%d", &a);
        map<int, int>::iterator it = m.find(a);
        if (it != m.end()) {
            int id = (*it).second;
            if (visited[id]) {
                printf("%04d: Checked\n", a);
            } else {
                visited[id] = true;
                if (id == 1) {
                    printf("%04d: Mystery Award\n", a);
                } else if (isPrime(id)) {
                    printf("%04d: Minion\n", a);
                } else {
                    printf("%04d: Chocolate\n", a);
                }
            }
        } else {
            printf("%04d: Are you kidding?\n", a);
        }
    }

    return 0;
}

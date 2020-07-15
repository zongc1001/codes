#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

const bool debug = false;

struct resFormat {
    int i, j, val;
    resFormat(int a, int b, int c) : i(a), j(b), val(c) {}
};

int dp[100000 + 5][20];
int val[100000 + 5];
int n, m;

int query(int begin, int end) {
    // if (debug) printf("\n--------entry query---------\n");
    if (begin == end) {
        // if (debug) printf("\n--------leave query---------\n");
        return dp[begin][0];
    }
    int rank = 0;
    int index = begin;
    int period = end - begin + 1;
    // if (debug) printf("start period: %d\n", period);
    int res = 0;

    int subperiod = 1;
    while (subperiod < period) {
        rank++;
        subperiod *= 2;
    }
    rank--;
    subperiod >>= 1;

    res += dp[begin][rank] + dp[end - subperiod + 1][rank];
    if (subperiod * 2 != period)
        res -= query(end - subperiod + 1, begin + pow(2, rank) - 1);
    return res;

    // while (period > 0) {
    //     if (period & 1) {
    //         res += dp[index][rank];
    //         index += pow(2, rank);
    //         // if (debug) printf("res: %d \n", res);
    //     }

    //     rank++;
    //     period /= 2;
    // }
    // // if (debug) printf("\n--------leave query---------\n");

    // return res;
}

int main(int argc, char const *argv[]) {
    if (debug) freopen("44", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &dp[i][0]);
    }

    for (int j = 1; pow(2, j) <= n; j++) {
        for (int i = 1; i + pow(2, j) - 1 <= n; i++) {
            dp[i][j] = dp[i][j - 1] + dp[i + int(pow(2, j - 1))][j - 1];
        }
    }
    if (debug) {
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 20; j++) {
                printf("%d ", dp[i][j]);
            }
            printf("\n");
        }
    }

    int min = 0x7fffffff;
    vector<resFormat> r;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int t = query(i, j);
            if (t <= min && t >= m) {
                min = t;
                r.push_back(resFormat(i, j, t));
            }
        }
    }
    for(int i = 0; i < r.size();i++)
    {
        if(r[i].val == min) 
        {
            printf("%d-%d\n", r[i].i, r[i].j );
        }
    }

    return 0;
}

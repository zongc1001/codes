#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

const bool debug = false;

struct resFormat {
    int i, j, val;
    resFormat(int a, int b, int c) : i(a), j(b), val(c) {}
    bool operator<(resFormat& obj) {
        if (val < obj.val)
            return true;
        else if (val == obj.val) {
            if (i < obj.i) {
                return true;
            } else if (i == obj.i) {
                if (j < obj.j) {
                    return true;
                }
            }
        }
        return false;
    }
};
int val[100000 + 5];
int n, m;
int main(int argc, char const* argv[]) {
    if (debug) freopen("44", "r", stdin);
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &val[i]);
    }

    int left = 1, right = 1;
    int curSum = val[1];
    vector<resFormat> r;
    while (left <= n && right <= n) {
        if (curSum < m) {
            right++;
            curSum += val[right];
        } else if (curSum == m) {
            r.push_back(resFormat(left, right, curSum));
            right++;
            curSum += val[right];
        } else if (curSum > m) {
            r.push_back(resFormat(left, right, curSum));
            if (left < right) {
                curSum -= val[left];
                left++;
            } else {
                right++;
                curSum += val[right];
            }
        }
    }
    sort(r.begin(), r.end());
    int min = r[0].val;
    for (int i = 0; i < r.size(); i++) {
        if (r[i].val == min) {
            printf("%d-%d\n", r[i].i, r[i].j); 
        }
    }

    return 0;
}

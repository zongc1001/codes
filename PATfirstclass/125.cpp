// https://pintia.cn/problem-sets/994805342720868352/problems/994805350316752896

#include <algorithm>
#include <cmath>
#include <cstdio>
#include <vector>
using namespace std;

bool debug = false;

int n;
vector<int> arr;

int main(int argc, char const *argv[]) {
    if(argc > 1) debug = true;
    if (debug) freopen("125", "r", stdin);
    scanf("%d", &n);
    arr.resize(n);
    int max = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        if (arr[i] > max) max = arr[i];
    }
    sort(arr.begin(), arr.end());
    int res = arr[0];
    bool carry;
    for (int i = 1; i < n; i++) {
        carry = res & 1;
        res /= 2;
        res += arr[i] / 2;
        if(carry && (arr[i] & 1)) {
            res ++;
            carry = false;
        }

        

    }
    printf("%d\n", res);
    return 0;
}

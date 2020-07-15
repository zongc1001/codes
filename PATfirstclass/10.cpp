// https://pintia.cn/problem-sets/994805342720868352/problems/994805507225665536

#include <cmath>
#include <iostream>
#include <string>
using namespace std;
const bool debug = true;

typedef unsigned long long ll;

string n1, n2;
int flag, radix;

ll toNum(char c) {
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    else
        return c - '0';
}

ll cal(string &s, ll rad) {
    // if (debug) printf("entry cal---------------\n");
    int n = s.size() - 1;
    ll res = 0;
    ll rank = 1;
    for (int i = n; i >= 0; i--) {
        res += toNum(s[i]) * rank;
        rank *= rad;

    }
    if(debug) cout << s << " " << rad << ": " << res << endl;
    return res;
}

ll search(string &s, ll target) {
    ll start = 0;
    for (int i = 0; i < s.size(); i++) {
        if (toNum(s[i]) > start) start = toNum(s[i]);
    }
    start++;
    ll end = max(target, start);
    // ll end = target;
    
    ll mid = (start + end) / 2;
    while (start <= end) {
        mid = (start + end) / 2;
        ll calRes = cal(s, mid);
        if (debug) printf("mid: %lld calRes: %lld\n", mid, calRes);
        if (calRes == target) {
            return mid;
        } else if (calRes < target) {
            start = mid + 1;
        } else if (calRes > target) {
            end = mid - 1;
        }
    }
    return -1;
}

string slice(string &s) {
    int k = -1;
    while (s[++k] == '0')
        ;
    return s.substr(k);
}

int main(int argc, char const *argv[]) {
    if (debug) freopen("10.txt", "r", stdin);
    cin >> n1 >> n2 >> flag >> radix;
    n1 = slice(n1);
    n2 = slice(n2);
    if (debug) {
        cout << "n1: " << n1 << endl;
        cout << "n2: " << n2 << endl;
    }
    ll res;
    if (flag == 1) {
        if (debug) {
            cout << "cal(n1, radix): " << cal(n1, radix) << endl;
        }
        res = search(n2, cal(n1, radix));
    } else {
        if (debug) {
            cout << "cal(n2, radix): " << cal(n2, radix) << endl;
        }
        res = search(n1, cal(n2, radix));
    }

    if (res != -1)
        cout << res << endl;
    else
        cout << "Impossible" << endl;

    return 0;
}

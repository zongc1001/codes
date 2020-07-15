// https://pintia.cn/problem-sets/994805342720868352/problems/1071785055080476672

#include <cmath>
#include <iostream>
#include <string>
using namespace std;
const bool debug = false;
typedef unsigned long long ull;

int l, k;
string a;


ull count(int begin, int end) {
    ull res = 0;
    ull rank = 1;
    for (int i = end; i >= begin; i--) {
        res += a[i] * rank;
        rank *= 10;
    }

    if(debug) {
        cout << "(begin, end, res): " << begin << " "
        << end << " " << res << endl;
    }
    return res;
}

bool isPrime(ull num) {
    if(num == 0) return false;
    if(num >= 1 && num <= 2) return true;
    for (int i = 2; i < sqrt(num) + 1; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

int main(int argc, char const *argv[]) {
    if(debug) freopen("152", "r", stdin);
    cin >> l >> k >> a;
    for (int i = 0; i < l; i++) {
        a[i] -= '0';
    }
    for (int i = 0; i <= l - k; i++) {
        if (isPrime(count(i, i + k - 1))) {
            for (int j = i; j <= i + k - 1; j++) {
                cout << char( a[j] + '0');
            }
            cout << endl;
            return 0;
        }
    }
    cout << 404 << endl;
    return 0;
}

// https://pintia.cn/problem-sets/994805342720868352/problems/994805378443755520

#include <cstdio>

using namespace std;
bool debug = false;

typedef long long ll;

struct obj {
    long up = 0;
    long down = 1;
    long k = 0;
    bool positive = true;
    obj() {}
    obj(long up, long down) : up(up), down(down) {}
};

void printObj(obj n) {
    bool neg;
    long k = n.up / n.down;
    if (n.up < 0) {
        neg = true;
        n.up = -n.up;
    }
    if (neg) {
        printf("(");
    }
    n.up -= k * n.down;
    long temp = 2;
    while (temp <= n.up) {
        if (n.up % temp == 0 && n.down % temp == 0) {
            n.up /= temp;
            n.down /= temp;
        } else {
            temp++;
        }
    }
    if (k == 0) {
        if (n.up == 0) {
            printf("0");
        } else {
            printf("%ld/%ld", n.up, n.down);
        }
    }
    else {
        if (n.up == 0) {
            printf("0");
        } else {
            printf("%d %ld/%ld", k, n.up, n.down);
        }
    }
    if (neg) {
        printf(")");
    }
}

obj calSum(obj& a, obj& b) {
    obj res;
    res.k = a.positive ? a.k : -a.k + b.positive ? b.k : -b.k;
    res.down = a.down * b.down;
    res.up = a.up * b.down + a.down * b.up;
    if (res.up > res.down) {
        res.up -= res.down;
        res.k++;
    }
    long temp = 2;
    while (temp <= res.up) {
        if (res.up % temp == 0 && res.down % temp == 0) {
            res.up /= temp;
            res.down /= temp;
        } else {
            temp++;
        }
    }

    return res;
}

int main(int argc, char const* argv[]) {
    if (argc > 1) debug = true;
    if (debug) freopen("88", "r", stdin);
    int a, b, c, d;
    scanf("%ld/%ld %ld/%ld", &a, &b, &c, &d);
    obj left(a, b);
    obj right(c, d);

    // if (debug) {
    //     printObj(left);
    //     printf(" ");
    //     printObj(right);
    // }
    obj temp;
    printObj(left);
    printf(" + ");
    printObj(right);
    printf(" = ");
    temp = calSum(left, right);
    printObj(temp);
    printf("\n");
    // printf("%ld/%ld %ld/%ld\n", left.up, left.down, right.up, right.down);
    return 0;
}

// https://pintia.cn/problem-sets/994805342720868352/problems/994805451374313472

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
bool debug = false;
ull nc, np;
vector<ull> coupon;
vector<ull> product;
vector<ull> negcoupon;
vector<ull> negproduct;

bool cmp(ull a, ull b) { return a > b; }
int main(int argc, char const *argv[]) {
    if(debug) freopen("37.txt", "r", stdin);
    scanf("%lld", &nc);
    for (int i = 0; i < nc; i++) {
        ll temp;
        scanf("%lld", &temp);
        if (temp > 0)
            coupon.push_back(temp);
        else if (temp < 0)
            negcoupon.push_back(-temp);
    }
    scanf("%lld", &np);
    for (int i = 0; i < np; i++) {
        ll temp;
        scanf("%lld", &temp);
        if (temp > 0)
            product.push_back(temp);
        else if (temp < 0)
            negproduct.push_back(-temp);
    }

    if(debug) {
        printf("%d %d\n", coupon.size(), negcoupon.size());
        printf("%d %d\n", product.size(), negproduct.size());
    }

    sort(coupon.begin(), coupon.end(), cmp);
    sort(product.begin(), product.end(), cmp);
    sort(negcoupon.begin(), negcoupon.end(), cmp);
    sort(negproduct.begin(), negproduct.end(), cmp);


    ull res = 0;
    int index = 0;

    while(index < product.size() && index < coupon.size())
    {
        res += product[index] * coupon[index];
        index++;
    }
    index = 0;
    while(index < negproduct.size() && index < negcoupon.size())
    {
        res += negproduct[index] * negcoupon[index];
        index++;
    }
    printf("%lld", res);

    


    return 0;
}

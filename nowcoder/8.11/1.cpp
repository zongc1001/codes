#include <cstdio>
#include <map>
#include <vector>
using namespace std;

bool debug = false;

const int col = 21;

int pow2[col];
map<int, vector<int>> table;

int min(int a, int b)
{
    return a < b ? a : b;
}
int max(int a, int b)
{
    return a > b ? a : b;
}

int main(int argc, char const *argv[])
{
    debug = argc > 1;
    if (debug)
    {
        freopen("1", "r", stdin);
    }

    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int temp;
        scanf("%d", &temp);
        minArr[i][0] = maxArr[i][0] = temp;
    }

    int q;
    scanf("%d", &q);
    while (q--)
    {
        int l, r, k;
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", findk(l - 1, r - 1, k));
    }

    return 0;
}

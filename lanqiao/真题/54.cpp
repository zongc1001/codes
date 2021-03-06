#include <cstdio>
#include <vector>
using namespace std;

bool debug = false;
int m, n;
int k;
int arr[1000000 + 10];
int findRoot(int n) {
    while (n != arr[n]) {
        n = arr[n];
    }
    return n;
}

int main(int argc, char const *argv[]) {
    if (argc > 1) debug = true;
    if (debug) freopen("54", "r", stdin);
    scanf("%d %d", &m, &n);
    scanf("%d", &k);
    if(debug) printf("%d %d %d \n", m, n, k);
    for (int i = 1; i <= m * n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (debug) printf("%d %d\n", a, b);
        int ra = findRoot(a);
        int rb = findRoot(b);
        //序号小的作为根
        if(ra < rb) arr[rb] = ra;
        else arr[ra] = rb;
    }

    if (debug) {
        printf("cin complete\n");
        for (int i = 1; i <= m * n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    
    vector<int> vec(m * n + 1);
    vec.assign(1 + m * n, 0);
    if (debug) {
        for (int i = 1; i <= m * n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    int res = 0;
    for (int i = 1; i <= m * n; i++) {
        
        if (arr[i] == i) res++;
    }
    

    printf("%d\n", res);
    return 0;
}

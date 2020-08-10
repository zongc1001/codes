#include <cstdio>
#include <vector>
using namespace std;

bool debug = false;
int m, n;
int k;
int arr[1000000 + 10];

void merge(int n) {
    vector<int> nums;

    while (n != arr[n]) {
        // if (debug) {
        //     printf("enter merge %d %d\n", n, arr[n]);
        // }
        nums.push_back(n);
        n = arr[n];
    }
    for (int i = 0; i < nums.size(); i++) {
        arr[nums[i]] = n;
    }
}

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
    printf("%d %d %d \n", m, n, k);
    for (int i = 1; i <= m * n; i++) {
        arr[i] = i;
    }

    for (int i = 0; i < k; i++) {
        int a, b;
        scanf("%d %d", &a, &b);
        if (debug) printf("%d %d\n", a, b);
        int t = findRoot(b);
        if (a > b) {
            int temp;
            temp = a;
            a = b;
            b = temp;
        }
        if (debug) {
            printf("cin %d %d\n", t, a);
        }
        arr[b] = a;
    }

    if (debug) {
        printf("cin complete\n");
        for (int i = 1; i <= m * n; i++) {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }

    // for (int i = 1; i <= m * n; i++) {
    //     merge(i);
    // }
    // if (debug) {
    //     printf("merge complete\n");
    // }
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
        // if (!vec[arr[i]]) {
        //     res++;
        //     vec[arr[i]] = 1;
        // }
        if (arr[i] == i) res++;
    }
    // if (debug) {
    //     for (int i = 1; i <= m * n; i++) {
    //         printf("%d ", vec[i]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", res);
    return 0;
}

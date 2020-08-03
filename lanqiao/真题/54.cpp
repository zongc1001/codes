#include <cstdio>
#include <vector>
using namespace std;

bool debug = false;
int m, n;
int k;
int arr[1000000 + 10];

void merge(int n)
{
    vector<int> nums;
    while (n != arr[n])
    {
        nums.push_back(n);
        n = arr[n];
    }
    for (int i = 0; i < nums.size(); i++)
    {
        arr[nums[i]] = n;
    }
}

int main(int argc, char const *argv[])
{
    if (argc > 1)
        debug = true;
    if (debug)
        freopen("54", "r", stdin);
    scanf("%d %d %d", &m, &n, &k);
    for (int i = 1; i <= m * n; i++)
    {
        arr[i] = i;
    }

    for (int i = 0; i < k; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        //
        if (a > b)
            arr[a] = b;
        else
            arr[b] = a;
    }
    for (int i = 1; i <= m * n; i++)
    {
        merge(i);
    }

    vector<int> vec(m * n + 1);
    vec.assign(1 + m * n, 0);
    if (debug)
    {
        for (int i = 1; i <= m * n; i++)
        {
            printf("%d ", arr[i]);
        }
        printf("\n");
    }
    int res = 0;
    for (int i = 1; i <= m * n; i++)
    {
        if (!vec[arr[i]])
        {
            res++;
            vec[arr[i]] = 1;
        }
    }
    if (debug)
    {
        for (int i = 1; i <= m * n; i++)
        {
            printf("%d ", vec[i]);
        }
        printf("\n");
    }
    
    printf("%d\n", res);
    return 0;
}

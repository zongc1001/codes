#include <cstdio>

using namespace std;

bool debug = false;

const int col = 21;
int minArr[300000 + 10][col];
int maxArr[300000 + 10][col];

int pow2[col];

int min(int a, int b)
{
    return a < b ? a : b;
}
int max(int a, int b)
{
    return a > b ? a : b;
}

//可以用二分改进
int findPow(int n)
{
    for (int i = 0; i < col; i++)
    {
        if (pow2[i] > n)
        {
            return i - 1;
        }
    }
}

int getMax(int start, int end, int pow)
{

    // if(debug) {
    //     printf("enter findk, start=%d, end=%d, k=%d\n", start, end, pow);
    // }
    return max(maxArr[start][pow], maxArr[end - pow2[pow] + 1][pow]);
}
int getMin(int start, int end, int pow)
{
    return min(minArr[start][pow], minArr[end - pow2[pow] + 1][pow]);
}

int findk(int start, int end, int k)
{
    if (debug)
    {
        printf("enter findk, start=%d, end=%d, k=%d\n", start, end, k);
    }
    if (start > end)
        return 0;
    int len = end - start + 1;
    int pow = findPow(len);
    int max = getMax(start, end, pow);
    int min = getMin(start, end, pow);
    // if (debug)
    // {
    //     printf("pow=%d, max=%d, min=%d\n", pow, max, min);
    // }
    if (max < k || min > k)
        return 0;
    if (max == min)
    {
        if (max == k)
        {
            if (debug)
            {
                printf("return len=%d\n", len);
            }
            return len;
        } else {
            return 0;
        }
    }
    else
    {
        // if(debug) {
        //     printf("%d != %d\n", max, min);
        // }
        return findk(start, start + len / 2 - 1, k) + findk(start + len / 2, end, k);
    }
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
    pow2[0] = 1;
    for (int i = 1; i < col; i++)
    {
        pow2[i] = pow2[i - 1] * 2;
    }

    for (int j = 1; j < col; j++)
    {
        for (int i = 0; i + pow2[j] - 1 < n; i++)
        {
            minArr[i][j] = min(minArr[i][j - 1], minArr[i + pow2[j - 1]][j - 1]);
            maxArr[i][j] = max(maxArr[i][j - 1], maxArr[i + pow2[j - 1]][j - 1]);
        }
    }
    if (debug)
    {
        printf("minArr: \n");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%d ", minArr[i][j]);
            }
            printf("\n");
        }
        printf("maxArr: \n");

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < col; j++)
            {
                printf("%d ", maxArr[i][j]);
            }
            printf("\n");
        }
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

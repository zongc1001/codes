#include <cstdio>
#include <string.h>
#include <vector>
#include <stack>
using namespace std;

int n, d;
const int MAX = 100000 + 5;

bool primeTable[MAX];

void createPrimeTable(bool *arr, int size)
{
    for (int i = 2; i < MAX / 2 + 1; i++)
    {
        if (primeTable[i])
        {
            for (int j = i + i; j < MAX; j += i)
            {
                primeTable[j] = false;
            }
        }
    }
}

int main(int argc, char const *argv[])
{
    memset(primeTable, true, sizeof(bool) * MAX);
    primeTable[0] = primeTable[1] = false;
    createPrimeTable(primeTable, MAX);
    // for (int i = 1; i < 100; i++)
    // {
    //     printf(primeTable[i] ? "%d:YES " : "%d:NO ", i);
    // }
    while (scanf("%d", &n))
    {
        if (n < 0)
            break;
        scanf("%d", &d);
        int realNum = 0;
        int rank = 1;

        stack<int> digits;
        int tempN = n;

        while (tempN > 0)
        {
            int temp = tempN % d;
            digits.push(temp);
            realNum += temp * rank;
            rank *= d;
            tempN /= d;
        }
        if (!primeTable[realNum])
        {
            printf("No\n");
            continue;
        }
        rank = 1;
        realNum = 0;
        while (!digits.empty())
        {
            realNum += rank * digits.top();
            rank *= d;
            digits.pop();
        }
        printf(primeTable[realNum] ? "Yes\n" : "No\n");
    }

    return 0;
}

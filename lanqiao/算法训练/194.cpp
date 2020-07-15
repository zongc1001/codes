//http://lx.lanqiao.cn/problem.page?gpid=T519

#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
typedef unsigned int uint;
typedef pair<uint, int> judgeAndSum; 

int n, m;
unsigned short table[1 << 20];

int main(int argc, char const *argv[])
{
    scanf("%d %d", &n, &m);
    
    for(int i = 0; i < n; i++)
    {
        int judge = 0;
        for(int j = 0; j < m; j++)
        {
            int temp;
            scanf("%d", &temp);
            judge <<= 1;
            judge += temp;
            
        }
        // printf("i: %d, judge: %d\n", i, judge);
        table[judge]++;
    }
    unsigned long long res = 0;
    int jie = (1 << m) - 1;
    for(int i = 0; i < (1 << (m-1)); i++)
    {
        res += table[i] * table[jie - i];
    }

    
    printf("%d\n", res);
    return 0;
}
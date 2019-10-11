#include <iostream>

using namespace std;
Coin pw[1000];
int dp[10005];
const int MAX = 0x7fffffff;

struct Coin
{
    /* data */
    int p, w;
};

int main(int argc, char const *argv[])
{
    int T;
    cin >> T;
    while(T--) {
        int E,F;
        int N;
        cin >> E >> F >> N;
        E = F-E;
        for(int i = 0; i < N; i++)
        {
            cin >> pw[i].p >> pw[i].w;
        }
        for(int i = 1; i < 10005;i++) {
            dp[i] = MAX;
        }
        dp[0] = 0;
        

    }
    

    return 0;
}

#include <iostream>

using namespace std;

unsigned long long ans = 0;

void dfs(int type, int sum)
{
    if (sum > 13)
        return;
    if (type == 13)
    {
        if (sum == 13)
            ans++;
        return;
    }

    for (int i = 0; i <= 4; i++)
    {
        dfs(type + 1, sum + i);
    }
}

int main(int argc, char const *argv[])
{
    dfs(0, 0);
    cout << ans << endl;
    return 0;
}

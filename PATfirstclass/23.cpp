//https://pintia.cn/problem-sets/994805342720868352/problems/994805478658260992

#include <iostream>
#include <string>
#include <vector>
using namespace std;
vector<int> sum;

int main(int argc, char const *argv[])
{
    string s;
    cin >> s;

    sum.assign(10, 0);
    int carry = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        sum[s[i] - '0']++;
        int temp = (s[i] - '0') * 2 + carry;
        if (temp >= 10)
        {
            temp -= 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        s[i] = temp + '0';
    }
    if (carry)
    {
        printf("No\n1%s", s.c_str());
        return 0;
    }
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (sum[s[i] - '0']-- == 0)
        {
            printf("No\n%s", s.c_str());
            return 0;
        }
    }

    printf("Yes\n%s", s.c_str());

    return 0;
}

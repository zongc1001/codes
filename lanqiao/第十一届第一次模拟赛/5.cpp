/*
【问题描述】<br>一个正整数如果任何一个数位不大于右边相邻的数位，
则称为一个数位递增的数，例如1135是一个数位递增的数，而1024不是一
个数位递增的数。<br>给定正整数 n，请问在整数 1 至 n 中有多少个数位
递增的数？<br>【输入格式】<br>输入的第一行包含一个整数 n。<br>
【输出格式】<br>输出一行包含一个整数，表示答案。<br>【样例输入】
<br>30<br>【样例输出】<br>26<br>【评测用例规模与约定】<br>
对于 40% 的评测用例，1 &lt;= n &lt;= 1000。<br>对于 80% 的评测用例，
1 <= n <= 100000。<br>对于所有评测用例，1 <= n &lt;= 1000000。
<br><br><br></p>

5004
*/

#include <iostream>

using namespace std;


bool is(int n)
{
    int last = 9;
    while(n > 0)
    {
        int temp = n % 10;
        if(temp <= last)
        {
            last = temp;
            n /= 10;
        }
        else
            return false;
    }
    return true;
}


int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans += is(i);
    }

    cout << ans << endl;


    return 0;
}

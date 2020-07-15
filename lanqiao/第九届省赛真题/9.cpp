/*

标题：倍数问题

【题目描述】
众所周知，小葱同学擅长计算，尤其擅长计算一个数是否是另外一个数的倍数。但小葱只擅长两个数的情况，当有很多个数之后就会比较苦恼。现在小葱给了你 n 个数，希望你从这 n 个数中找到三个数，使得这三个数的和是 K 的倍数，且这个和最大。数据保证一定有解。

【输入格式】
从标准输入读入数据。

第一行包括 2 个正整数 n, K。
第二行 n 个正整数，代表给定的 n 个数。

【输出格式】
输出到标准输出。
输出一行一个整数代表所求的和。

【样例入】
4 3
1 2 3 4

【样例输出】
9

【样例解释】
选择2、3、4。

【数据约定】
对于 30% 的数据，n <= 100。
对于 60% 的数据，n <= 1000。
对于另外 20% 的数据，K <= 10。
对于 100% 的数据，1 <= n <= 10^5, 1 <= K <= 10^3，给定的 n 个数均不超过 10^8。


资源约定：
峰值内存消耗（含虚拟机） < 256M
CPU消耗  < 1000ms


请严格按要求输出，不要画蛇添足地打印类似：“请您输入...” 的多余内容。

注意：
main函数需要返回0;
只使用ANSI C/ANSI C++ 标准;
不要调用依赖于编译环境或操作系统的特殊函数。
所有依赖的函数必须明确地在源文件中 #include <xxx>
不能通过工程设置而省略常用头文件。

提交程序时，注意选择所期望的语言类型和编译器类型。
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, k;
int arr[100000 + 10];

typedef pair<int, int> con;
typedef vector<con> li;
vector<li> table;

bool cmp(int a, int b)
{
    return a > b;
}

int main(int argc, char const *argv[])
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    sort(arr, arr + n, cmp);
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    table.resize(k + 1);
    for (int i = 0; i < n; i++)
    {
        table[arr[i] % k].push_back(con(arr[i], i));
    }
    // table[arr[n-1] % k].push_back(con(arr[n-1], n-1));
    // remain[n-1] = arr[n-1] % k;
    unsigned int max = 0;
    for (int i = 0; i <= n - 3; i++)
    {
        for (int j = i + 1; j <= n - 2; j++)
        {
            int temp = k - (arr[i] + arr[j]) % k;
            for(int t = 0; t < table[temp].size(); t++)
            {
                if(table[temp][i].second > j)
                {
                    int a = arr[i] + arr[j] + table[temp][i].first;
                    if(a > max)
                    {
                        max = a;
                    }
                }
            }
        }
    }

    cout << max << endl;

    return 0;
}

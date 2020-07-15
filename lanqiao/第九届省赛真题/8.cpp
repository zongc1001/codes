/* 

标题：全球变暖


【题目描述】
你有一张某海域NxN像素的照片，"."表示海洋、"#"表示陆地，如下所示：

.......
.##....
.##....
....##.
..####.
...###.
.......

其中"上下左右"四个方向上连在一起的一片陆地组成一座岛屿。例如上图就有2座岛屿。  

由于全球变暖导致了海面上升，科学家预测未来几十年，岛屿边缘一个像素的范围会被海水淹没。具体来说如果一块陆地像素与海洋相邻(上下左右四个相邻像素中有海洋)，它就会被淹没。  

例如上图中的海域未来会变成如下样子：

.......
.......
.......
.......
....#..
.......
.......

请你计算：依照科学家的预测，照片中有多少岛屿会被完全淹没。  

【输入格式】
第一行包含一个整数N。  (1 <= N <= 1000)  
以下N行N列代表一张海域照片。  

照片保证第1行、第1列、第N行、第N列的像素都是海洋。  

【输出格式】
一个整数表示答案。

【样例输入】
7 
.......
.##....
.##....
....##.
..####.
...###.
.......  

【样例输出】
1  


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
#include <queue>
#include <algorithm>
using namespace std;

typedef pair<int, int> axis;

bool vistied[1000 + 5][100 + 5];
bool arr[1000 + 5][1000 + 5];
int step[4][2] = {
    {-1, 0},
    {1, 0},
    {0, -1},
    {0, 1}};
/*
对于当前结点, 如果该节点未被访问过, 并且周围的全是陆地, 
就可以判断当前的岛屿不会被完全淹没
*/
bool search(axis cur)
{
    int a = cur.first;
    int b = cur.second;
    vistied[a][b] = true;
    queue<axis> q;

    q.push(cur);
    bool res = false;
    while (!q.empty())
    {
        int a = q.front().first;
        int b = q.front().second;
        q.pop();
        bool is = true;
        for (int i = 0; i < 4; i++)
        {
            int x = a + step[i][0];
            int y = b + step[i][1];
            if (!arr[x][y])
                is = false;
            if (!vistied[x][y] && arr[x][y])
            {
                vistied[x][y] = true;
                q.push(axis(x, y));
            }
        }
        if (is)
            res = true;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char temp;
            cin >> temp;
            if (temp == '#')
                arr[i][j] = true;
        }
    }

    int res = 0;
    for (int i = 1; i < n - 1; i++)
    {
        for (int j = 1; j < n - 1; j++)
        {
            // if (!vistied[i][j])
            //     cout << i << ", " << j << " " << search(axis(i, j)) << endl;
            if (!vistied[i][j] && search(axis(i, j)))
                res++;
        }
    }
    cout << res << endl;

    return 0;
}

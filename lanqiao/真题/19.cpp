#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int shift[9][4] = {
    {1, 3, -1, -1},
    {0, 2, 4, -1},
    {1, 5, -1, -1},
    {0, 4, 6, -1},
    {1, 3, 5, 7},
    {2, 4, 8, -1},
    {3, 7, -1, -1},
    {6, 4, 8, -1},
    {5, 7, -1, -1}};

struct Obj
{
    /* data */
    string str;
    short pos;
    Obj(string s, short p) : str(s), pos(p) {}
};

queue<Obj> que; //存放状态的队列

long int fac[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880}; //阶乘表

int congtuo(string s)
{
    int res = 0;
    int n = s.length();
    for (int i = 0; i < n - 1; i++)
    {
        int temp = 0;
        for (int j = i + 1; j < n; j++)
        {
            if (s[j] < s[i])
            {
                temp++;
            }
        }
        res += temp * fac[n - i - 1];
    }
    return res;
}

bool visited[362880 + 10]; //9的阶乘

int main(int argc, char const *argv[])
{
    string src, dst;
    cin >> src >> dst;

    int cur;       //空格当前位置
    int last = -1; //空格上一位置
    cur = src.find('.');

    // cout << cur << " " << last << endl;
    // cout << congtuo(string("3124")) << endl;

    int loop = -1;                  //循环的层数
    int target = congtuo(dst);      //目标状态
    que.push(Obj(src, cur));        //压入初始的状态
    while (true)
    {
        int numsOfCurLevel = que.size();       //一层为一个外循环
        if (numsOfCurLevel == 0)                //队列中无元素， 结束，没有解法
        {
            break;
        }
        loop++;                                 //层数++                    
        while (numsOfCurLevel--)                //遍历当前层
        {
            Obj tempObj = que.front();
            que.pop();
            int order = congtuo(tempObj.str);
            if (order == target)                //寻找到目标状态
            {
                cout << loop << endl;
                return 0;
            }
            if (!visited[order])                //若未访问过，压入子节点
            {
                visited[order] = true;
                for(int i = 0; i < 4 ;i++)
                {
                    int nextPos = shift[tempObj.pos][i];
                    if(nextPos < 0) break;
                    Obj temp(tempObj.str, nextPos);
                    temp.str[tempObj.pos] = temp.str[nextPos];
                    temp.str[nextPos] = '.';
                    que.push(temp);
                }
            }

        }

    }
    cout << -1 << endl;
    return 0;
}

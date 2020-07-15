/*
标题：跳蚱蜢

如图 p1.png 所示： 
有9只盘子，排成1个圆圈。
其中8只盘子内装着8只蚱蜢，有一个是空盘。
我们把这些蚱蜢顺时针编号为 1~8

每只蚱蜢都可以跳到相邻的空盘中，
也可以再用点力，越过一个相邻的蚱蜢跳到空盘中。

请你计算一下，如果要使得蚱蜢们的队形改为按照逆时针排列，
并且保持空盘的位置不变（也就是1-8换位，2-7换位,...），至少要经过多少次跳跃？

注意：要求提交的是一个整数，请不要填写任何多余内容或说明文字。

ans: 20
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
#include <string>
using namespace std;

int step[4] = {1, -1, 2, -2};

string origin("012345678");
string target("087654321");

queue<pair<string, int> > que;
set<string> store;

int main(int argc, char const *argv[])
{
    que.push(pair<string, int>(origin, 0));
    store.insert(origin);
    string cur = que.front().first;

    int level = -1;
    bool notFound = true;
    while (!que.empty())
    {  
        level++;
        cout << "level: " <<level << endl;
       
        int looptimes = que.size();
        for(int i = 0; i < looptimes; i++)
        {
            // cout << "loop: " << looptimes <<endl;
            pair<string, int> s = que.front();
             que.pop();
            if(s.first == target)
            {
                cout << "find in : " << level << endl;
                notFound = false;
                break;
            }
            for(int j = 0;j < 4; j++)
            {
                int pos = (step[j] + s.second + 9) % 9;
                pair<string, int> temp;
                temp.first = string(s.first);
                temp.first[s.second] = temp.first[pos];
                temp.first[pos] = '0';
                temp.second = pos;
                

                if(store.find(temp.first) == store.end())
                {
                    // cout << temp.first <<endl;
                    store.insert(temp.first);
                    que.push(temp);
                }
            }
            

        }
        

    }
    





    return 0;
}

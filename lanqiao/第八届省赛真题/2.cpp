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

ans:
*/

#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <algorithm>
using namespace std;

string origin("012345678");
string target("087654321");

queue<string> que;
set<pair<string, int>> store;

int main(int argc, char const *argv[])
{
    




    return 0;
}

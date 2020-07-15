/*
<p>【问题描述】<br>1200000有多少个约数（只计算正约数）。<br>
【答案提交】<br>这是一道结果填空的题，你只需要算出结果后提交即可。
本题的结果为一个整数，在提交答案时只填写这个整数，填写多余的内容将无法得分。
<br><br><br></p>

ans：96
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int ans = 2;
    for(int i = 2; i <= 600000;i++)
    {
        if(1200000 % i == 0)
        {
            ans++;
        }
    }
    cout << ans << endl;


    return 0;
}
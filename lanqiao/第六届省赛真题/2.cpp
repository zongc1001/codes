/*

星系炸弹

在X星系的广袤空间中漂浮着许多X星人造“炸弹”，用来作为宇宙中的路标。
每个炸弹都可以设定多少天之后爆炸。
比如：阿尔法炸弹2015年1月1日放置，定时为15天，则它在2015年1月16日爆炸。
有一个贝塔炸弹，2014年11月9日放置，定时为1000天，请你计算它爆炸的准确日期。

请填写该日期，格式为 yyyy-mm-dd  即4位年份2位月份2位日期。比如：2015-02-19
请严格按照格式书写。不能出现其它文字或符号。

2017-08-05
*/

#include <iostream>

using namespace std;

bool isCurRun;
int maxDay;
int maxMonth = 12;



bool isRun(int a)
{
    return a % 400 == 0 || (a % 4 == 0 && a % 100 != 0);
}

int main(int argc, char const *argv[])
{
    int y = 2011, m = 11, d = 11;
    cin >> y >> m >> d;
    

    while(true)
    {

    }


    return 0;
}

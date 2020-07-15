/*
方程整数解

方程: a^2 + b^2 + c^2 = 1000
（或参见【图1.jpg】）
这个方程有整数解吗？有：a,b,c=6,8,30 就是一组解。
你能算出另一组合适的解吗？

请填写该解中最小的数字。

注意：你提交的应该是一个整数，不要填写任何多余的内容或说明性文字。

解：-30
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    for (int a = 0; a <= 100; a++)
    {
        for (int b = 0; b <= 100; b++)
        {
            for (int c = 0; c <= 100; c++)
            {
                if(a * a + b * b + c * c == 1000)
                    cout << a << " " << b << " " << c << endl;
            }
        }
    }

    return 0;
}

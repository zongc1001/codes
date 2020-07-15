/*
<p>【问题描述】<br>在1至2019中，有多少个数的数位中包含数字9？<br>
注意，有的数中的数位中包含多个9，这个数只算一次。例如，1999这个数包含数字9
，在计算只是算一个数。<br>【答案提交】<br>这是一道结果填空的题，
你只需要算出结果后提交即可。本题的结果为一个整数，在提交答案时只填写这个整数，
填写多余的内容将无法得分。<br><br><br><br></p>

ans: 544
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int ans = 0;
    for(int i = 1; i <= 2019;i++)
    {
        int temp = i;
        while(temp > 0)
        {
            if(temp % 10 == 9)
            {
                ans++;
                break;
            }
            temp /= 10;
        }



    }
    cout << ans << endl;

    return 0;
}

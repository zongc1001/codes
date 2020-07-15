/*

手链样式

小明有3颗红珊瑚，4颗白珊瑚，5颗黄玛瑙。
他想用它们串成一圈作为手链，送给女朋友。
现在小明想知道：如果考虑手链可以随意转动或翻转，一共可以有多少不同的组合样式呢？

请你提交该整数。不要填写任何多余的内容或说明性的文字。

ans:1320
*/


#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
    string arr("aaabbbbccccc");
    unsigned long long a = 0;

    vector<string> vec;

    do
    {
        // cout << "213" << endl;
        int i;
        for(i = 0; i < vec.size();i++)
        {
            if(vec[i].find(arr) != string::npos)
                break;    
        }
        
        if(i != vec.size()) continue;
        a++;
        string temp = arr + arr;
        vec.push_back(temp);

        reverse(temp.begin(), temp.end());
        vec.push_back(temp);

    } while (next_permutation(arr.begin(), arr.end()));

    cout << a << endl;

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

vector<string> s(2);

int tag;
int radix;

int main(int argc, char const *argv[])
{
    cin >> s[0] >> s[1] >> tag >> radix;

    // cout << s[0] << " " << s[1] << " " << tag << " " << radix << " " << endl;

    tag -= 1;

    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < s[i].size(); j++)
        {
            if (s[i][j] >= '0' && s[i][j] <= '9')
                s[i][j] -= '0';
            else if (s[i][j] >= 'a' && s[i][j] <= 'z')
                s[i][j] -= 'a' - 10;
        }
    }

    unsigned long long target = 0;
    int len = s[tag].size();
    for (int i = len - 1; i >= 0; i--)
    {
        target += s[tag][i] * pow(radix, len - i - 1);
    }

    tag = tag ^ 1;
    // cout << "target: " << target << endl;
    // cout << "tag: " << tag << endl;

    len = s[tag].size();
    bool is = false;
    int index = -1;
    
    
    //检查1进制的情况
    // bool isAll1 = true;
    // for(int i = len - 1; i >= 0; i--)
    // {
    //     if(s[tag][i] != 1)
    //     {
    //         isAll1 = false;
    //         break;
    //     }
    // }
    // if(isAll1 && target == len)
    // {
    //     cout << 1 << endl;
    //     return 0;
    // }


    for(int i = len - 1; i >= 0; i--)
    {
        if(s[tag][i] > index)
            index = s[tag][i];
    }
    index++;

    // cout << "index: " << index << endl;
    for (; index <= 36; index++)
    {
        unsigned long long temp = 0;
        for (int i = len - 1; i >= 0; i--)
        {
            temp += s[tag][i] * pow(index, len - i - 1);
        }
        
        if (temp == target)
        {
            is = true;
            break;
        }
        else if(temp > target)
        {
            break;
        }
        
    }

    if (is)
    {
        cout << index << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }

    return 0;
}

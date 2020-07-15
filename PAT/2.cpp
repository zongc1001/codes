//https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384

#include <iostream>
#include <string>
#include <algorithm>

#include <vector>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;
    string arr[10] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << endl;
    // }
    while (cin >> s)
    {
        vector<int> a;
        int sum = 0;
        for (int i = 0; i < s.length(); i++)
        {
            sum += s[i] - '0';
        }
        while (sum > 0)
        {
            a.push_back(sum % 10);
            sum /= 10;
        }
        for(int i = a.size()- 1; i >= 0;i--) 
        {
            cout << arr[a[i]];
            if(i != 0) {
                cout << " ";
            }
        }

        cout << endl;
    }

    return 0;
}

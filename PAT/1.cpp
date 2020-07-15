/*
https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528
*/

#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    int n;
    int res;
    while (cin >> n)
    {
        res = 0;
        while (n != 1)
        {
            res++;
            if (n & 1)
            {
                n *= 3;
                n += 1;
                n >>= 1;
            } 
            else 
            {
                n >>=1;
            }
        }
        cout << res << endl;
    }
    
    return 0;
}

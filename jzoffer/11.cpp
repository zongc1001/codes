#include<iostream>
using namespace std;

class Solution {
public:
     int  NumberOf1(int n) {
        int res = 0;
        int numOf0 = 0;
        bool met1 = false;
        int temp = n > 0 ? n : -n;
        while(temp != 0) {
            if(temp & 1 > 0) {
                res++;
                met1 = true;
            } 
            else if(!met1) {
                numOf0++;
            } 
            
            temp /= 2;
        }
        if(n >= 0) return res;
        else return 32 - numOf0 - res + 1;
     }
};

int main(int argc, char const *argv[])
{
    Solution s;
    int n;
    while(true) {
        cin >> n;
        cout << s.NumberOf1(n) << endl;
    }
    return 0;
}

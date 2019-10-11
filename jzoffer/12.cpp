#include<iostream>

#include<cmath>

using namespace std;

class Solution {
public:
    double Power(double base, int exponent) {
        if(base == 0) 
            return 0;
        if(exponent == 0) 
            return 1;
        double res = base;
        int exp = abs(exponent);
        for(int i = 1; i < exp; i++) {
            res *= base;
        }
        return exponent > 0 ? res : 1 / res;
    }
};
int main(int argc, char const *argv[])
{
    cout << pow(2.4,10);
    return 0;
}

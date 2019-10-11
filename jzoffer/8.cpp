#include <iostream>

using namespace std;
class Solution {
public:
    int jumpFloor(int number) {
        // int a1 = 1;
        // int a2 = 2;
        if(number <= 2) 
            return number;
        else {
            return jumpFloor(number-1) + jumpFloor(number-2);
        }
    }
};
int main(int argc, char const *argv[])
{
    



    return 0;
}

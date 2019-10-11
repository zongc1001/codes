#include <iostream>

using namespace std;
class Solution {
public:
    int jumpFloor(int number) {
        
        if(number <= 2) 
            return number;
        else {
            int temp = 0;
            for(int i = 1; i < number;i++) {
                temp = temp + jumpFloor(number-i);
            }
            return temp + 1;
        }
    }
};
int main(int argc, char const *argv[])
{
    cout << Solution().jumpFloor(5);




    return 0;
}

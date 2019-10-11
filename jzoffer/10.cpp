#include<iostream>

using namespace std;

class Solution {
public:
    int rectCover(int number) {
        if(number<=2) 
            return number;
        else {
            return rectCover(number-1) + rectCover(number-2);
        }
    }
};

int main(int argc, char const *argv[])
{

    return 0;
}

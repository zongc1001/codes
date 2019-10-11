#include<iostream>

using namespace std;

class Solution {
public:
    int Fibonacci(int n) {
        int a = 0;
        int b = 1;
        int c = 1;
        if(n<=1) return n;

        for(int i = 0; i < n - 1;i++) {
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
};

int main() {
    Solution s;
    cout << s.Fibonacci(3);
}
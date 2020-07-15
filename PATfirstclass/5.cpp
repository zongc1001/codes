#include <iostream>
#include <stack>
#include <string>
#include <algorithm>
using namespace std;

char s[102];

string arr[10] = {
    "zero", "one", "two", "three", "four", "five",
    "six", "seven", "eight", "nine"};

int main(int argc, char const *argv[])
{
    while (cin >> s)
    {
        int sum = 0;
        int i = 0;
        while(s[i] != '\0')
        {
            sum += s[i++] - '0';
        }
        if(sum == 0) 
        {
            cout << "zero" << endl;
            continue;
        }
        // cout << sum << endl;
        stack<int> stk;
        while (sum > 0)
        {
            stk.push(sum % 10);
            sum /= 10;
        }
        cout << arr[stk.top()];
        stk.pop();
        while (!stk.empty())
        {
            cout << " " << arr[stk.top()];
            stk.pop();
        }
        cout << endl;
    }
    return 0;
}

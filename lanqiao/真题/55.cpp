
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
bool debug = false;

unsigned int chToNum(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    } else if (c >= 'A' && c <= 'Z') {
        return c - 'A' + 10;
    }
    return -1;
}

unsigned long long decode(string s, unsigned int k) {
    unsigned long long index = 1;
    unsigned long long res = 0;
    for (int i = s.length() - 1; i >= 0; i--) {
        res += index * chToNum(s[i]);
        index *= k;
    }
    // if(debug) {
    //     cout << "decode: " << s << " -> " << res << endl;
    // }
    return res;
}

string encode(unsigned long long num, unsigned int k) {
    if(num == 0) return "0";
    vector<unsigned int> nums;
    while (num > 0) {
        nums.push_back(num % k);
        num /= k;
    }
    char s[nums.size()];
    string res = "";
    for (int i = nums.size() - 1; i >= 0; i--) {
        string temp;
        if (nums[i] >= 0 && nums[i] <= 9) {
            temp = '0' + nums[i];
        } else {
            temp = 'A' + nums[i] - 10;
        }
        res.append(temp);
    }
    return res;
}

int main(int argc, char const *argv[]) {
    if (argc > 1) debug = true;
    if (debug) freopen("55", "r", stdin);

    int numOfOrder = 0;
    cin >> numOfOrder;
    bool clear = true;
    unsigned long long num = 0;
    int curIndex = 10;
    char curOp = ' ';
    while (numOfOrder--) {
        string temp;
        cin >> temp;
        if (temp == "CLEAR") {
            clear = true;
        } else if (temp == "NUM") {
            string n;
            cin >> n;
            unsigned long long tempNum = decode(n, curIndex);
            if (curOp == ' ' && clear) {
                clear = false;
                num = tempNum;
            } else {
                if (curOp == '+') {
                    num += tempNum;
                } else if (curOp == '-') {
                    num -= tempNum;
                } else if (curOp == '*') {
                    num *= tempNum;
                } else if (curOp == '/') {
                    num /= tempNum;
                } else if (curOp == '%') {
                    num %= tempNum;
                }
                curOp = ' ';
            }
        } else if (temp == "CHANGE") {
            cin >> curIndex;
        } else if (temp == "EQUAL") {
            cout << encode(num, curIndex) << endl;
        } else if (temp == "ADD") {
            curOp = '+';
        } else if (temp == "SUB") {
            curOp = '-';
        } else if (temp == "MUL") {
            curOp = '*';
        } else if (temp == "DIV") {
            curOp = '/';
        } else if (temp == "MOD") {
            curOp = '%';
        }
    }
    return 0;
}

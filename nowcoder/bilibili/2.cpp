/*
判断由"()[]{}"6种括号组成的字符串是否合法
1. 所有括号必须闭合
2. 左括号必须在正确的位置闭合
*/

#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isLeft(char c) {
  if(c == '(' || c == '{' || c == '[') {
    return true;
  }
  return false;
}

int main(int argc, char const *argv[])
{
  string s;
  cin >> s;
  if(s[0] != '"' || s[s.length()-1] != '"') {
    cout << "No" << endl;
    return;
  }
  bool flag = true;
  stack<char> stk;
  for (int i = 1; i < s.length() - 1; i++)
  {
    


  }

  return 0;
}

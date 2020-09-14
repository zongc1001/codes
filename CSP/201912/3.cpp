#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <queue>
using namespace std;

int n;
string s;
typedef pair<string, int> peer;
int table[30][30];
int index;



//匹配系数
int matchXiuu()
{

}

//匹配化学式
int matchExp()
{
}

//匹配项
int matchItem()
{
}

//匹配元素
int matchElem()
{
}

int main(int argc, char const *argv[])
{
  cin >> n;
  while (n--)
  {
    cin >> s;
    map<string, int> left;
    map<string, int> right;
    int posOfEqual = 0;
    for (int i = 0; i < s.length(); i++)
    {
      if (s[i] == '=')
      {
        posOfEqual = i;
      }
    }
    stack<string> stk;
    for (int i = 0; i < posOfEqual; i++)
    {
      string curElem;
      int cur;
      if (s[i] >= 'A' && s[i] <= 'Z')
      {
        int lengthOfElem = 1;
        if (s[i + 1] >= 'a' && s[i + 1] <= 'z')
        {
          lengthOfElem++;
        }

        stk.push(s.substr(i, lengthOfElem));
      }
    }
  }

  return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
string s;
int len;
fstream output;
string space = "";
vector<int> resSequence;
vector<vector<int> > checkedRes;

bool check()
{
    int len = checkedRes.size();
    if (len == 0)
        return true;
    else if (len > 1)
        return false;
    else if (len == 1)
    {
        if (resSequence.size() != checkedRes[0].size())
        {
            return true;
        }
        else
        {
            bool isEqual = true;
            for (int i = 0; i < resSequence.size(); i++)
            {
                if (resSequence[i] != checkedRes[0][i])
                {
                    isEqual = false;
                    break;
                }
            }
            if (isEqual)
                return false;
        }
    }
}

int recur(int index, int l, int n)
{
    space += "  ";
    if (index == len)
    {
        if (l == 0 && n == 0)
        {
            space = space.substr(2);
            bool checkRes = check();
            resSequence.clear();
            return checkRes;
        }
        else
        {
            space = space.substr(2);
            resSequence.clear();

            return 0;
        }
    }
    else
    {
        if (n > l)
        {
            space = space.substr(2);
            resSequence.clear();

            return 0;
        }
        if (index < len && s[index] == '0')
        {
            resSequence.push_back(index);
            while (index < len && s[index] == '0')
            {
                index++;
                l--;
            }
            resSequence.push_back(index);
        }

        if (index == len && l == 0 && n == 0)
        {
            space = space.substr(2);
            int checkRes = check();
            resSequence.clear();
            return checkRes;
        }
        else
        {
            int numOf1 = 0;
            int numOfRes = 0;
            for (int i = index; i < len; i++)
            {
                numOf1 = numOf1 * 2 + s[i] - '0';

                if (numOf1 > n || numOf1 > l)
                {
                    break;
                }
                else
                {
                    output << space << i + 1 << " " << l - numOf1 << " " << n - numOf1 << endl;
                    int temp = recur(i + 1, l - numOf1, n - numOf1);
                    output << space << temp << endl;
                    numOfRes += temp;
                }
            }

            space = space.substr(2);

            return numOfRes;
        }
    }
}

int main(int argc, char const *argv[])
{
    int l, n;
    cin >> l >> n >> s;
    len = s.length();
    output.open("out.txt");
    int res = recur(0, l, n);

    cout << checkedRes.size();

    // cout << res;

    cout << endl;

    return 0;
}
